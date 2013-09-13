
from select import select

from cffi import FFI

ffi= FFI()

ffi.cdef(open('egl.h').read())
ffi.cdef(open('gl.h').read())
lib= ffi.verify(open('test.c').read(),libraries=['EGL','GL'])

EGL_VERSION_MAJOR=ffi.new('EGLint*',0)
EGL_VERSION_MINOR=ffi.new('EGLint*',0)

def errors(key,errors={}):
    if errors:
        return errors.get(key,"Unknow {0}".format(key))
    errors.update( (
        (lib.NOT_INITIALIZED,
            "EGL is not initialized, or could not be initialized, for the specified EGL display connection."),
        (lib.BAD_ACCESS,
            "EGL cannot access a requested resource (for example a context is bound in another thread)."),
        (lib.BAD_ALLOC,
            "EGL failed to allocate resources for the requested operation."),
        (lib.BAD_ATTRIBUTE,
            "An unrecognized attribute or attribute value was passed in the attribute list."),
        (lib.BAD_CONTEXT,
            "An EGLContext argument does not name a valid EGL rendering context."),
        (lib.BAD_CONFIG,
            "An EGLConfig argument does not name a valid EGL frame buffer configuration."),
        (lib.BAD_CURRENT_SURFACE,
            "The current surface of the calling thread is a window, pixel buffer or pixmap that is no longer valid."),
        (lib.BAD_DISPLAY,
            "An EGLDisplay argument does not name a valid EGL display connection."),
        (lib.BAD_SURFACE,
            "An EGLSurface argument does not name a valid surface (window, pixel buffer or pixmap) configured for GL rendering."),
        (lib.BAD_MATCH,
            "Arguments are inconsistent (for example, a valid context requires buffers not supplied by a valid surface)."),
        (lib.BAD_PARAMETER,
            "One or more argument values are invalid."),
        (lib.BAD_NATIVE_PIXMAP,
            "A NativePixmapType argument does not refer to a valid native pixmap."),   
        (lib.BAD_NATIVE_WINDOW,
            "A NativeWindowType argument does not refer to a valid native window."),
        (lib.CONTEXT_LOST,
            "A power management event has occurred. The application must destroy all contexts and reinitialise OpenGL ES state and objects to continue rendering. " ) ) )
    return errors.get(key,"Unknow {0}".format(key))


class X11ConnectionObject:
	    
    def __init__(self,address=None):
        if address is None:
            self.display = lib.XOpenDisplay(ffi.NULL)
            self.last_event= ffi.new('XEvent*')
            self.windows= []
    
    def __del__( self ):
        lib.XCloseDisplay(self.display)
    
    def createWindow(self,x=10,y=10,w=300,h=200):
        self.screen= lib.XDefaultScreen(self.display)
        w = lib.XCreateSimpleWindow(self.display, lib.XRootWindow(self.display, self.screen), x,y,w,h, 1,
                               lib.XBlackPixel(self.display, self.screen), lib.XWhitePixel(self.display, self.screen))
        lib.XSelectInput(self.display, w, lib.X11_ExposureMask | lib.X11_KeyPressMask)
        lib.XMapWindow(self.display, w)
        lib.XNextEvent( self.display, self.last_event )
        self.windows.append( w )
        return w

    def fileno(self):
        return lib.XConnectionNumber( self.display )

    def getEvent(self):
        lib.XNextEvent( self.display, self.last_event )
        return self.last_event
        

def create_X11_window():
    d = lib.XOpenDisplay(ffi.NULL)
    s = lib.XDefaultScreen(d)
    w = lib.XCreateSimpleWindow(d, lib.XRootWindow(d, s), 10, 10, 300, 200, 1,
                           lib.XBlackPixel(d, s), lib.XWhitePixel(d, s))
    lib.XSelectInput(d, w, lib.X11_ExposureMask | lib.X11_KeyPressMask)
    lib.XMapWindow(d, w)
    e= ffi.new('XEvent*')
    lib.XNextEvent( d, e )
    return d,w

def run():
    display = lib.eglGetDisplay(lib.DEFAULT_DISPLAY)
    r= lib.eglInitialize(display,EGL_VERSION_MAJOR,EGL_VERSION_MINOR)
    
    if r == lib.TRUE:
        print("EGL Version {0}.{1} initialized.".format(EGL_VERSION_MAJOR[0],EGL_VERSION_MINOR[0]))
    else:
        print("EGL Version {0}.{1} failed to initialize: {2}".format(EGL_VERSION_MAJOR[0],EGL_VERSION_MINOR[0],errors(lib.eglGetError())))
        return 

    config_attribute_list= ffi.new('EGLint[]',[lib.RED_SIZE,1,lib.GREEN_SIZE,1,lib.BLUE_SIZE,1,lib.DEPTH_SIZE,1,lib.RENDERABLE_TYPE,lib.OPENGL_ES2_BIT,lib.NONE])
    config=ffi.new('EGLConfig*')
    num_config=ffi.new('EGLint*',0)
    
    lib.eglChooseConfig(display, config_attribute_list, config, 1, num_config)
    
    lib.eglBindAPI(lib.OPENGL_API)
    
    context= lib.eglCreateContext(display, config[0], lib.NO_CONTEXT, ffi.NULL)
    if context == lib.NO_CONTEXT:
        print("eglCreateWindowSurface failed: {0}".format(errors(lib.eglGetError())))
        return 
    
    native_connection= X11ConnectionObject()
    
    surface_attribute_list= ffi.new('EGLint[]',[lib.NONE])
    surface = lib.eglCreateWindowSurface(display, config[0], native_connection.createWindow(), ffi.NULL)
    if surface == lib.NO_SURFACE:
        print("eglCreateWindowSurface failed: {0}".format(errors(lib.eglGetError())))
        return
    
    lib.eglMakeCurrent(display, surface, surface, context)
    
    print("GL_RENDERER   = %s\n", ffi.string(lib.glGetString(lib._GL_RENDERER)))
    print("GL_VERSION    = %s\n", ffi.string(lib.glGetString(lib._GL_VERSION)))
    print("GL_VENDOR     = %s\n", ffi.string(lib.glGetString(lib._GL_VENDOR)))
    print("GL_EXTENSIONS = %s\n", ffi.string(lib.glGetString(lib._GL_EXTENSIONS)))
     
    native_keysyms_per_keycode_return= ffi.new('int*')
		
    rlist= [native_connection]
	
    while True:
        inputready,outputready,exceptready = select( rlist, [], [], 1 )
        if native_connection in inputready:
            
            native_event= native_connection.getEvent()

            if native_event.type == lib.X11_Expose:
                lib.eglMakeCurrent(display, surface, surface, context)
                lib.glClearColor(1.0, 1.0, 0.0, 1.0)
                lib.glClear(lib._GL_COLOR_BUFFER_BIT)
                lib.glFlush()
                lib.eglSwapBuffers(display, surface)
                print("Expose Event")
            elif native_event.type == lib.X11_KeyPress:
                if native_event.xkey.keycode == 9:
                    print("Button Event: Escape pressed. Bye!")
                    return 
                else:
                    native_keysym = lib.XGetKeyboardMapping(native_connection.display,
                        native_event.xkey.keycode, 1,
                        native_keysyms_per_keycode_return)
                    print("Button Event: {1}({0}) pressed.".format( native_keysym[0], ffi.string( lib.XKeysymToString( native_keysym[0] ) ) )  )
                lib.eglMakeCurrent(display, surface, surface, context)
                lib.glClearColor(1.0, 0.0, 1.0, 1.0)
                lib.glClear(lib._GL_COLOR_BUFFER_BIT)
                lib.glFlush()
                lib.eglSwapBuffers(display, surface)
            else:
                print("Event of type {0}.".format(native_event.type))
        else:
            lib.eglMakeCurrent(display, surface, surface, context)
            lib.glClearColor(0.0, 1.0, 0.0, 1.0)
            lib.glClear(lib._GL_COLOR_BUFFER_BIT)
            lib.glFlush()
            lib.eglSwapBuffers(display, surface)
		
    
    
    
   
if __name__ == "__main__":
    run()
    
    
