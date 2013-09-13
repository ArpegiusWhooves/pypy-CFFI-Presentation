

from cffi import FFI
ffi= FFI()

import inspect

def lineno():
    """Returns the current line number in our program."""
    no= inspect.currentframe().f_back.f_lineno
    return no

if hasattr( __builtins__, 'xrange'):
	range=xrange

ffi.cdef( "# %d\""%(lineno()+1,) + __file__ + """"
	struct serobj {
		int a,b,c;
		char x[12]; v
		struct serobj* p;		
	};
	void setserobj(  struct serobj * a,  struct serobj * b );
	void loopserobj(  struct serobj * ser,  int TIMES );
	
	
""" );


lib= ffi.verify( "# %d\""%(lineno()+1,) + __file__ + """"
	struct serobj {
		int a,b,c;
		char x[12];z
		struct serobj* p;
	};
	
	void setserobj(  struct serobj * s,  struct serobj * p )
	{
		s->a=p->a+1;
		s->b=p->a+s->a;
		s->c=p->b+s->a;
		s->x[4]='0';
		s->p=p;
	};
	
	void loopserobj(  struct serobj * ser,  int TIMES )
	{
		int p= TIMES-1;
		int i;
		for( i= 0; i < TIMES; ++i)
		{
			ser[i].a=ser[p].a+1;
			ser[i].b=ser[p].a+ser[i].a;
			ser[i].c=ser[p].b+ser[i].a;
			ser[i].x[4]='0';
			ser[i].p=ser+p;
			p=i;
		}
	}
	
""");

class Ser:
	def __init__(self):
		self.a=0
		self.b=0
		self.c=0
		self.x=[b"\0"]*12
		self.p=None

def run_empty():
	t=[None for x in range( TIMES )]
	for i,s in enumerate(t):
			pass
	

def run_cffi():
	ser= ffi.new( "struct serobj[]", TIMES )
	p=ser[TIMES-1]
	p.a=1
	for i,s in enumerate(ser):
		s.a=p.a+1
		s.b=p.a+s.a
		s.c=p.b+s.a
		s.x[4]=b"0"
		s.p=ffi.addressof(p)
		p=s

def run_cffi_undirect():
	ser= ffi.new( "struct serobj[]", TIMES )
	p=TIMES-1
	ser[p].a=1
	for i in range(TIMES):
		ser[i].a=ser[p].a+1
		ser[i].b=ser[p].a+ser[i].a
		ser[i].c=ser[p].b+ser[i].a
		ser[i].x[4]=b"0"
		ser[i].p=ser+p
		p=i

def run_c_undirect():
	ser= ffi.new( "struct serobj[]", TIMES )
	p=ser+(TIMES-1)
	p.a=1
	st=lib.setserobj
	for i in range(TIMES):
		st( ser+i, p )
		p=ser+i

def run_c_noloop():
	ser= ffi.new( "struct serobj[]", TIMES )
	lib.loopserobj( ser, TIMES )
		
def run_object_undirect():
	ser= [ Ser() for x in range(TIMES) ]
	p=TIMES-1
	ser[p].a=1
	for i in range(TIMES):
		ser[i].a=ser[p].a+1
		ser[i].b=ser[p].a+ser[i].a
		ser[i].c=ser[p].b+ser[i].a
		ser[i].x[4]=b"0"
		ser[i].p=ser[p]
		p=i
		
def run_object():
	ser= [ Ser() for x in range(TIMES) ]
	p=ser[TIMES-1]
	p.a=1
	for i,s in enumerate(ser):
		s.a=p.a+1
		s.b=p.a+s.a
		s.c=p.b+s.a
		s.x[4]=b"0"
		s.p=p
		p=s
		
import timeit


def run_test( test ):
	val= timeit.timeit( '__main__.'+test+'()', 'import __main__', number=LOOPS )
	print(  "%20s %6.5f"%(test,val) )
	
def run_tests(times,loops):
	global TIMES,LOOPS
	TIMES=times
	LOOPS=loops
	
	print("Running {0} loops of {1} objects.".format(LOOPS,TIMES))
	
	run_test("run_empty")
	run_test("run_cffi")
	run_test("run_cffi_undirect")
	run_test("run_c_undirect")
	run_test("run_c_noloop")
	run_test("run_object")
	run_test("run_object_undirect")

run_tests(10,1000)
run_tests(100,100)
run_tests(1000,10)
run_tests(10000,1)

exit()

	

