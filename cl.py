
from select import select

from cffi import FFI

ffi= FFI()

ffi.cdef(open('cl.h').read())
#ffi.cdef(open('gl.h').read())
lib= ffi.verify(open('cl.c').read(),libraries=['OpenCL'])

PLATFORMS_ID=ffi.new('cl_platform_id[4]',0)
PLATFORM_COUNT=ffi.new('cl_uint*',0)



err= clGetPlatformIDs(4 ,
                 PLATFORMS_ID ,
                 PLATFORM_COUNT )

if err != 0:
	print err
