import numpy

SerializedObjectType=[
    ('name','a12'),
    ('a','i4'),
    ('b','i4'),
    ('d','f4'),
    ('f','f4')]


fileRecords=1024*1024*128

array = numpy.memmap(
    filename="/media/home/test2.dat",
    dtype=SerializedObjectType,
    mode="r+",
    shape=(fileRecords,) )

print array

#for j in range(0, fileRecords, 1024*1024 ):
#    empties= array[j:j+1024*1024]['a'] == 0
#    if numpy.any(empties):
#        print "Found empty ", numpy.where(empties)
#        break
#    print "Range ", j, "-", min( j+1024*1024, fileRecords), " filed."

starti=0

if starti < fileRecords - 1:
    print "Starting from ",starti,":", array[starti]['name']
    for j in range(starti, fileRecords, 1024*1024 ):
        for i in range(j, min( j+1024*1024, fileRecords) ):
            a = 1 + ( i*18446744073709551557)%2147483647
            b = 1 + ( 18446744073709551557^i)%2147483647
            array[i]= ("Object" + str(i)[:6], a, b, a*100.0/b, b*100.0/a)

#import random
#for i in range(10):
#    j=random.randint(0,fileRecords)
#    array[j]['a'] = 0
