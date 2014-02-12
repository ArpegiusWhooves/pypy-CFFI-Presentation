#!/usr/bin/env python
# -*- coding: utf-8 -*-


from cffi import FFI
ffi= FFI()

ffi.cdef( """
struct SerializedObject {
    char name[12];
    int a,b;
    float d,f;
};

void *mmap(void *addr, size_t length, int prot, int flags, int fd, size_t offset);
int munmap(void *addr, size_t length);

""")

fileRecords=1024*1024*128

fileSize=ffi.sizeof('struct SerializedObject')*fileRecords

f=open('/media/home/test2.dat','rw+b')
f.truncate(fileSize)

#addr=, length=0, prot=PROT_NONE, flags=MAP_PRIVATE, fd=0, offset=0

#import mmap
Maps = ffi.dlopen(None);

print "Maps Function:", Maps.mmap

MAP_FAILED = ffi.cast( "void*", -1 )

PROT_READ=0x1
PROT_WRITE=0x2
MAP_SHARED=0x1
MAP_PRIVATE=0x2

datapointer= Maps.mmap(ffi.NULL,fileSize, PROT_READ|PROT_WRITE, MAP_SHARED, f.fileno() ,0)

if MAP_FAILED == datapointer:
    raise RuntimeError,"Map failed"

print "Data Pointer:", datapointer

array= ffi.cast( 'struct SerializedObject *', datapointer )

import base64

f.flush()

for j in range(0, fileRecords, 1024*1024 ):
    for starti in range(j, min( j+1024*1024, fileRecords) ):
        if array[starti].a == 0:
            print "Found empty ", starti
            break
    print "Range ", starti, "-", min( j+1024*1024, fileRecords), " filed."

if starti < fileRecords - 1:
    print "Starting from ",starti,":", ffi.string(array[starti].name)
    for j in range(starti, fileRecords, 1024*1024 ):
        for i in range(j, min( j+1024*1024, fileRecords) ):
            array[i].name= "Object" + str(i)[:6]
            array[i].a = (1 + i*5321234^423134)%2147483647
            array[i].b = (1 + i*437212340^i)%2147483647
            array[i].d = array[i].a * 100.0 / array[i].b
            array[i].f = array[i].b * 100.0 / array[i].a
        print "flushing ",j,"-", min( j+1024*1024, fileRecords)
        f.flush()

print "Unmaping", Maps.munmap( datapointer, fileSize )
