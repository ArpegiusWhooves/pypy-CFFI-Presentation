


typedef int8_t cl_char;
typedef uint8_t cl_uchar;
typedef int16_t cl_short ;
typedef uint16_t cl_ushort;
typedef int32_t cl_int;
typedef uint32_t cl_uint;
typedef int64_t cl_long;
typedef uint64_t cl_ulong;

typedef uint16_t cl_half;
typedef float cl_float;
typedef double cl_double;



typedef unsigned int cl_GLuint;
typedef int cl_GLint;
typedef unsigned int cl_GLenum;
 

typedef union
{
    cl_char  s[2];

    struct{ cl_char x, y; };
    struct{ cl_char s0, s1; };
    struct{ cl_char lo, hi; };




}cl_char2;

typedef union
{
    cl_char   s[4];

    struct{ cl_char x, y, z, w; };
    struct{ cl_char s0, s1, s2, s3; };
    struct{ cl_char2 lo, hi; };







}cl_char4;


typedef cl_char4 cl_char3;

typedef union
{
    cl_char   s[8];

    struct{ cl_char x, y, z, w; };
    struct{ cl_char s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_char4 lo, hi; };

    

}cl_char8;

typedef union
{
    cl_char   s[16];

    struct{ cl_char x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_char s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_char8 lo, hi; };

    


    

}cl_char16;



typedef union
{
    cl_uchar  s[2];

    struct{ cl_uchar x, y; };
    struct{ cl_uchar s0, s1; };
    struct{ cl_uchar lo, hi; };




}cl_uchar2;

typedef union
{
    cl_uchar  s[4];

    struct{ cl_uchar x, y, z, w; };
    struct{ cl_uchar s0, s1, s2, s3; };
    struct{ cl_uchar2 lo, hi; };







}cl_uchar4;


typedef cl_uchar4 cl_uchar3;

typedef union
{
    cl_uchar s[8];

   struct{ cl_uchar x, y, z, w; };
   struct{ cl_uchar s0, s1, s2, s3, s4, s5, s6, s7; };
   struct{ cl_uchar4 lo, hi; };


}cl_uchar8;

typedef union
{
    cl_uchar  s[16];

    struct{ cl_uchar x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_uchar s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_uchar8 lo, hi; };


}cl_uchar16;



typedef union
{
    cl_short  s[2];

    struct{ cl_short x, y; };
    struct{ cl_short s0, s1; };
    struct{ cl_short lo, hi; };




}cl_short2;

typedef union
{
    cl_short  s[4];

    struct{ cl_short x, y, z, w; };
    struct{ cl_short s0, s1, s2, s3; };
    struct{ cl_short2 lo, hi; };





    

}cl_short4;


typedef cl_short4 cl_short3;

typedef union
{
    cl_short  s[8];

    struct{ cl_short x, y, z, w; };
    struct{ cl_short s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_short4 lo, hi; };





    


    

}cl_short8;

typedef union
{
    cl_short  s[16];

    struct{ cl_short x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_short s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_short8 lo, hi; };





    


    




}cl_short16;



typedef union
{
    cl_ushort  s[2];

    struct{ cl_ushort x, y; };
    struct{ cl_ushort s0, s1; };
    struct{ cl_ushort lo, hi; };




}cl_ushort2;

typedef union
{
    cl_ushort  s[4];

    struct{ cl_ushort x, y, z, w; };
    struct{ cl_ushort s0, s1, s2, s3; };
    struct{ cl_ushort2 lo, hi; };





    

}cl_ushort4;


typedef cl_ushort4 cl_ushort3;

typedef union
{
    cl_ushort  s[8];

    struct{ cl_ushort x, y, z, w; };
    struct{ cl_ushort s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_ushort4 lo, hi; };





    


    

}cl_ushort8;

typedef union
{
    cl_ushort  s[16];

    struct{ cl_ushort x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_ushort s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_ushort8 lo, hi; };





    


    




}cl_ushort16;


typedef union
{
    cl_int  s[2];

    struct{ cl_int x, y; };
    struct{ cl_int s0, s1; };
    struct{ cl_int lo, hi; };


    

}cl_int2;

typedef union
{
    cl_int  s[4];

    struct{ cl_int x, y, z, w; };
    struct{ cl_int s0, s1, s2, s3; };
    struct{ cl_int2 lo, hi; };


    


    

}cl_int4;


typedef cl_int4 cl_int3;

typedef union
{
    cl_int  s[8];

    struct{ cl_int x, y, z, w; };
    struct{ cl_int s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_int4 lo, hi; };


    


    




}cl_int8;

typedef union
{
    cl_int  s[16];

    struct{ cl_int x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_int s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_int8 lo, hi; };


    


    







}cl_int16;



typedef union
{
    cl_uint  s[2];

    struct{ cl_uint x, y; };
    struct{ cl_uint s0, s1; };
    struct{ cl_uint lo, hi; };


    

}cl_uint2;

typedef union
{
    cl_uint  s[4];

    struct{ cl_uint x, y, z, w; };
    struct{ cl_uint s0, s1, s2, s3; };
    struct{ cl_uint2 lo, hi; };


    


    

}cl_uint4;


typedef cl_uint4 cl_uint3;

typedef union
{
    cl_uint  s[8];

    struct{ cl_uint x, y, z, w; };
    struct{ cl_uint s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_uint4 lo, hi; };


    


    




}cl_uint8;

typedef union
{
    cl_uint  s[16];

    struct{ cl_uint x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_uint s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_uint8 lo, hi; };


    


    







}cl_uint16;


typedef union
{
    cl_long  s[2];

    struct{ cl_long x, y; };
    struct{ cl_long s0, s1; };
    struct{ cl_long lo, hi; };


    

}cl_long2;

typedef union
{
    cl_long  s[4];

    struct{ cl_long x, y, z, w; };
    struct{ cl_long s0, s1, s2, s3; };
    struct{ cl_long2 lo, hi; };


    




}cl_long4;


typedef cl_long4 cl_long3;

typedef union
{
    cl_long  s[8];

    struct{ cl_long x, y, z, w; };
    struct{ cl_long s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_long4 lo, hi; };


    







}cl_long8;

typedef union
{
    cl_long  s[16];

    struct{ cl_long x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_long s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_long8 lo, hi; };


    

}cl_long16;



typedef union
{
    cl_ulong  s[2];

    struct{ cl_ulong x, y; };
    struct{ cl_ulong s0, s1; };
    struct{ cl_ulong lo, hi; };


    

}cl_ulong2;

typedef union
{
    cl_ulong  s[4];

    struct{ cl_ulong x, y, z, w; };
    struct{ cl_ulong s0, s1, s2, s3; };
    struct{ cl_ulong2 lo, hi; };


    




}cl_ulong4;


typedef cl_ulong4 cl_ulong3;

typedef union
{
    cl_ulong  s[8];

    struct{ cl_ulong x, y, z, w; };
    struct{ cl_ulong s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_ulong4 lo, hi; };


    







}cl_ulong8;

typedef union
{
    cl_ulong  s[16];

    struct{ cl_ulong x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_ulong s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_ulong8 lo, hi; };


    

}cl_ulong16;




typedef union
{
    cl_float  s[2];

    struct{ cl_float x, y; };
    struct{ cl_float s0, s1; };
    struct{ cl_float lo, hi; };


    

}cl_float2;

typedef union
{
    cl_float  s[4];

    struct{ cl_float x, y, z, w; };
    struct{ cl_float s0, s1, s2, s3; };
    struct{ cl_float2 lo, hi; };


    


    

}cl_float4;


typedef cl_float4 cl_float3;

typedef union
{
    cl_float  s[8];

    struct{ cl_float x, y, z, w; };
    struct{ cl_float s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_float4 lo, hi; };


    


    




}cl_float8;

typedef union
{
    cl_float  s[16];

    struct{ cl_float x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_float s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_float8 lo, hi; };


    


    







}cl_float16;



typedef union
{
    cl_double  s[2];

    struct{ cl_double x, y; };
    struct{ cl_double s0, s1; };
    struct{ cl_double lo, hi; };


    

}cl_double2;

typedef union
{
    cl_double  s[4];

    struct{ cl_double x, y, z, w; };
    struct{ cl_double s0, s1, s2, s3; };
    struct{ cl_double2 lo, hi; };


    




}cl_double4;


typedef cl_double4 cl_double3;

typedef union
{
    cl_double  s[8];

    struct{ cl_double x, y, z, w; };
    struct{ cl_double s0, s1, s2, s3, s4, s5, s6, s7; };
    struct{ cl_double4 lo, hi; };


    







}cl_double8;

typedef union
{
    cl_double  s[16];

    struct{ cl_double x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    struct{ cl_double s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    struct{ cl_double8 lo, hi; };
 

}cl_double16;


typedef struct _cl_platform_id * cl_platform_id;
typedef struct _cl_device_id * cl_device_id;
typedef struct _cl_context * cl_context;
typedef struct _cl_command_queue * cl_command_queue;
typedef struct _cl_mem * cl_mem;
typedef struct _cl_program * cl_program;
typedef struct _cl_kernel * cl_kernel;
typedef struct _cl_event * cl_event;
typedef struct _cl_sampler * cl_sampler;

typedef cl_uint cl_bool;
typedef cl_ulong cl_bitfield;
typedef cl_bitfield cl_device_type;
typedef cl_uint cl_platform_info;
typedef cl_uint cl_device_info;
typedef cl_bitfield cl_device_fp_config;
typedef cl_uint cl_device_mem_cache_type;
typedef cl_uint cl_device_local_mem_type;
typedef cl_bitfield cl_device_exec_capabilities;
typedef cl_bitfield cl_command_queue_properties;

typedef intptr_t cl_context_properties;
typedef cl_uint cl_context_info;
typedef cl_uint cl_command_queue_info;
typedef cl_uint cl_channel_order;
typedef cl_uint cl_channel_type;
typedef cl_bitfield cl_mem_flags;
typedef cl_uint cl_mem_object_type;
typedef cl_uint cl_mem_info;
typedef cl_uint cl_image_info;
typedef cl_uint cl_buffer_create_type;
typedef cl_uint cl_addressing_mode;
typedef cl_uint cl_filter_mode;
typedef cl_uint cl_sampler_info;
typedef cl_bitfield cl_map_flags;
typedef cl_uint cl_program_info;
typedef cl_uint cl_program_build_info;
typedef cl_int cl_build_status;
typedef cl_uint cl_kernel_info;
typedef cl_uint cl_kernel_work_group_info;
typedef cl_uint cl_event_info;
typedef cl_uint cl_command_type;
typedef cl_uint cl_profiling_info;

typedef struct _cl_image_format {
    cl_channel_order image_channel_order;
    cl_channel_type image_channel_data_type;
} cl_image_format;


typedef struct _cl_buffer_region {
    size_t origin;
    size_t size;
} cl_buffer_region;

extern cl_int
clGetPlatformIDs(cl_uint ,
                 cl_platform_id * ,
                 cl_uint * ) ;

extern cl_int
clGetPlatformInfo(cl_platform_id ,
                  cl_platform_info ,
                  size_t ,
                  void * ,
                  size_t * ) ;


extern cl_int
clGetDeviceIDs(cl_platform_id ,
               cl_device_type ,
               cl_uint ,
               cl_device_id * ,
               cl_uint * ) ;

extern cl_int
clGetDeviceInfo(cl_device_id ,
                cl_device_info ,
                size_t ,
                void * ,
                size_t * ) ;


extern cl_context
clCreateContext(const cl_context_properties * ,
                cl_uint ,
                const cl_device_id * ,
                void ( * )(const char *, const void *, size_t, void *),
                void * ,
                cl_int * ) ;

extern cl_context
clCreateContextFromType(const cl_context_properties * ,
                        cl_device_type ,
                        void ( * )(const char *, const void *, size_t, void *),
                        void * ,
                        cl_int * ) ;

extern cl_int
clRetainContext(cl_context ) ;

extern cl_int
clReleaseContext(cl_context ) ;

extern cl_int
clGetContextInfo(cl_context ,
                 cl_context_info ,
                 size_t ,
                 void * ,
                 size_t * ) ;


extern cl_command_queue
clCreateCommandQueue(cl_context ,
                     cl_device_id ,
                     cl_command_queue_properties ,
                     cl_int * ) ;

extern cl_int
clRetainCommandQueue(cl_command_queue ) ;

extern cl_int
clReleaseCommandQueue(cl_command_queue ) ;

extern cl_int
clGetCommandQueueInfo(cl_command_queue ,
                      cl_command_queue_info ,
                      size_t ,
                      void * ,
                      size_t * ) ;

extern cl_mem
clCreateBuffer(cl_context ,
               cl_mem_flags ,
               size_t ,
               void * ,
               cl_int * ) ;

extern cl_mem
clCreateSubBuffer(cl_mem ,
                  cl_mem_flags ,
                  cl_buffer_create_type ,
                  const void * ,
                  cl_int * ) ;

extern cl_mem
clCreateImage2D(cl_context ,
                cl_mem_flags ,
                const cl_image_format * ,
                size_t ,
                size_t ,
                size_t ,
                void * ,
                cl_int * ) ;

extern cl_mem
clCreateImage3D(cl_context ,
                cl_mem_flags ,
                const cl_image_format * ,
                size_t ,
                size_t ,
                size_t ,
                size_t ,
                size_t ,
                void * ,
                cl_int * ) ;

extern cl_int
clRetainMemObject(cl_mem ) ;

extern cl_int
clReleaseMemObject(cl_mem ) ;

extern cl_int
clGetSupportedImageFormats(cl_context ,
                           cl_mem_flags ,
                           cl_mem_object_type ,
                           cl_uint ,
                           cl_image_format * ,
                           cl_uint * ) ;

extern cl_int
clGetMemObjectInfo(cl_mem ,
                   cl_mem_info ,
                   size_t ,
                   void * ,
                   size_t * ) ;

extern cl_int
clGetImageInfo(cl_mem ,
               cl_image_info ,
               size_t ,
               void * ,
               size_t * ) ;

extern cl_int
clSetMemObjectDestructorCallback( cl_mem ,
                                    void ( * )( cl_mem , void* ),
                                    void * ) ;


extern cl_sampler
clCreateSampler(cl_context ,
                cl_bool ,
                cl_addressing_mode ,
                cl_filter_mode ,
                cl_int * ) ;

extern cl_int
clRetainSampler(cl_sampler ) ;

extern cl_int
clReleaseSampler(cl_sampler ) ;

extern cl_int
clGetSamplerInfo(cl_sampler ,
                 cl_sampler_info ,
                 size_t ,
                 void * ,
                 size_t * ) ;


extern cl_program
clCreateProgramWithSource(cl_context ,
                          cl_uint ,
                          const char ** ,
                          const size_t * ,
                          cl_int * ) ;

extern cl_program
clCreateProgramWithBinary(cl_context ,
                          cl_uint ,
                          const cl_device_id * ,
                          const size_t * ,
                          const unsigned char ** ,
                          cl_int * ,
                          cl_int * ) ;

extern cl_int
clRetainProgram(cl_program ) ;

extern cl_int
clReleaseProgram(cl_program ) ;

extern cl_int
clBuildProgram(cl_program ,
               cl_uint ,
               const cl_device_id * ,
               const char * ,
               void ( * )(cl_program , void * ),
               void * ) ;

extern cl_int
clUnloadCompiler(void) ;

extern cl_int
clGetProgramInfo(cl_program ,
                 cl_program_info ,
                 size_t ,
                 void * ,
                 size_t * ) ;

extern cl_int
clGetProgramBuildInfo(cl_program ,
                      cl_device_id ,
                      cl_program_build_info ,
                      size_t ,
                      void * ,
                      size_t * ) ;


extern cl_kernel
clCreateKernel(cl_program ,
               const char * ,
               cl_int * ) ;

extern cl_int
clCreateKernelsInProgram(cl_program ,
                         cl_uint ,
                         cl_kernel * ,
                         cl_uint * ) ;

extern cl_int
clRetainKernel(cl_kernel ) ;

extern cl_int
clReleaseKernel(cl_kernel ) ;

extern cl_int
clSetKernelArg(cl_kernel ,
               cl_uint ,
               size_t ,
               const void * ) ;

extern cl_int
clGetKernelInfo(cl_kernel ,
                cl_kernel_info ,
                size_t ,
                void * ,
                size_t * ) ;

extern cl_int
clGetKernelWorkGroupInfo(cl_kernel ,
                         cl_device_id ,
                         cl_kernel_work_group_info ,
                         size_t ,
                         void * ,
                         size_t * ) ;


extern cl_int
clWaitForEvents(cl_uint ,
                const cl_event * ) ;

extern cl_int
clGetEventInfo(cl_event ,
               cl_event_info ,
               size_t ,
               void * ,
               size_t * ) ;

extern cl_event
clCreateUserEvent(cl_context ,
                  cl_int * ) ;

extern cl_int
clRetainEvent(cl_event ) ;

extern cl_int
clReleaseEvent(cl_event ) ;

extern cl_int
clSetUserEventStatus(cl_event ,
                     cl_int ) ;

extern cl_int
clSetEventCallback( cl_event ,
                    cl_int ,
                    void ( * )(cl_event, cl_int, void *),
                    void * ) ;


extern cl_int
clGetEventProfilingInfo(cl_event ,
                        cl_profiling_info ,
                        size_t ,
                        void * ,
                        size_t * ) ;


extern cl_int
clFlush(cl_command_queue ) ;

extern cl_int
clFinish(cl_command_queue ) ;


extern cl_int
clEnqueueReadBuffer(cl_command_queue ,
                    cl_mem ,
                    cl_bool ,
                    size_t ,
                    size_t ,
                    void * ,
                    cl_uint ,
                    const cl_event * ,
                    cl_event * ) ;

extern cl_int
clEnqueueReadBufferRect(cl_command_queue ,
                        cl_mem ,
                        cl_bool ,
                        const size_t * ,
                        const size_t * ,
                        const size_t * ,
                        size_t ,
                        size_t ,
                        size_t ,
                        size_t ,
                        void * ,
                        cl_uint ,
                        const cl_event * ,
                        cl_event * ) ;

extern cl_int
clEnqueueWriteBuffer(cl_command_queue ,
                     cl_mem ,
                     cl_bool ,
                     size_t ,
                     size_t ,
                     const void * ,
                     cl_uint ,
                     const cl_event * ,
                     cl_event * ) ;

extern cl_int
clEnqueueWriteBufferRect(cl_command_queue ,
                         cl_mem ,
                         cl_bool ,
                         const size_t * ,
                         const size_t * ,
                         const size_t * ,
                         size_t ,
                         size_t ,
                         size_t ,
                         size_t ,
                         const void * ,
                         cl_uint ,
                         const cl_event * ,
                         cl_event * ) ;

extern cl_int
clEnqueueCopyBuffer(cl_command_queue ,
                    cl_mem ,
                    cl_mem ,
                    size_t ,
                    size_t ,
                    size_t ,
                    cl_uint ,
                    const cl_event * ,
                    cl_event * ) ;

extern cl_int
clEnqueueCopyBufferRect(cl_command_queue ,
                        cl_mem ,
                        cl_mem ,
                        const size_t * ,
                        const size_t * ,
                        const size_t * ,
                        size_t ,
                        size_t ,
                        size_t ,
                        size_t ,
                        cl_uint ,
                        const cl_event * ,
                        cl_event * ) ;

extern cl_int
clEnqueueReadImage(cl_command_queue ,
                   cl_mem ,
                   cl_bool ,
                   const size_t * ,
                   const size_t * ,
                   size_t ,
                   size_t ,
                   void * ,
                   cl_uint ,
                   const cl_event * ,
                   cl_event * ) ;

extern cl_int
clEnqueueWriteImage(cl_command_queue ,
                    cl_mem ,
                    cl_bool ,
                    const size_t * ,
                    const size_t * ,
                    size_t ,
                    size_t ,
                    const void * ,
                    cl_uint ,
                    const cl_event * ,
                    cl_event * ) ;

extern cl_int
clEnqueueCopyImage(cl_command_queue ,
                   cl_mem ,
                   cl_mem ,
                   const size_t * ,
                   const size_t * ,
                   const size_t * ,
                   cl_uint ,
                   const cl_event * ,
                   cl_event * ) ;

extern cl_int
clEnqueueCopyImageToBuffer(cl_command_queue ,
                           cl_mem ,
                           cl_mem ,
                           const size_t * ,
                           const size_t * ,
                           size_t ,
                           cl_uint ,
                           const cl_event * ,
                           cl_event * ) ;

extern cl_int
clEnqueueCopyBufferToImage(cl_command_queue ,
                           cl_mem ,
                           cl_mem ,
                           size_t ,
                           const size_t * ,
                           const size_t * ,
                           cl_uint ,
                           const cl_event * ,
                           cl_event * ) ;

extern void *
clEnqueueMapBuffer(cl_command_queue ,
                   cl_mem ,
                   cl_bool ,
                   cl_map_flags ,
                   size_t ,
                   size_t ,
                   cl_uint ,
                   const cl_event * ,
                   cl_event * ,
                   cl_int * ) ;

extern void *
clEnqueueMapImage(cl_command_queue ,
                  cl_mem ,
                  cl_bool ,
                  cl_map_flags ,
                  const size_t * ,
                  const size_t * ,
                  size_t * ,
                  size_t * ,
                  cl_uint ,
                  const cl_event * ,
                  cl_event * ,
                  cl_int * ) ;

extern cl_int
clEnqueueUnmapMemObject(cl_command_queue ,
                        cl_mem ,
                        void * ,
                        cl_uint ,
                        const cl_event * ,
                        cl_event * ) ;

extern cl_int
clEnqueueNDRangeKernel(cl_command_queue ,
                       cl_kernel ,
                       cl_uint ,
                       const size_t * ,
                       const size_t * ,
                       const size_t * ,
                       cl_uint ,
                       const cl_event * ,
                       cl_event * ) ;

extern cl_int
clEnqueueTask(cl_command_queue ,
              cl_kernel ,
              cl_uint ,
              const cl_event * ,
              cl_event * ) ;

extern cl_int
clEnqueueNativeKernel(cl_command_queue ,
       void (*user_func)(void *),
                      void * ,
                      size_t ,
                      cl_uint ,
                      const cl_mem * ,
                      const void ** ,
                      cl_uint ,
                      const cl_event * ,
                      cl_event * ) ;

extern cl_int
clEnqueueMarker(cl_command_queue ,
                cl_event * ) ;

extern cl_int
clEnqueueWaitForEvents(cl_command_queue ,
                       cl_uint ,
                       const cl_event * ) ;

extern cl_int
clEnqueueBarrier(cl_command_queue ) ;

extern void * clGetExtensionFunctionAddress(const char * ) ;
