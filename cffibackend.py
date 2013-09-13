

import _cffi_backend as _cffi


_ALL_PRIMITIVE_TYPES = {
	'char':               'c',
	'short':              'i',
	'int':                'i',
	'long':               'i',
	'long long':          'i',
	'signed char':        'i',
	'unsigned char':      'u',
	'unsigned short':     'u',
	'unsigned int':       'u',
	'unsigned long':      'u',
	'unsigned long long': 'u',
	'float':              'f',
	'double':             'f',
	'long double':        'f',
	'_Bool':              'u',
	# the following types are not primitive in the C sense
	'wchar_t':            'c',
	'int8_t':             'i',
	'uint8_t':            'u',
	'int16_t':            'i',
	'uint16_t':           'u',
	'int32_t':            'i',
	'uint32_t':           'u',
	'int64_t':            'i',
	'uint64_t':           'u',
	'intptr_t':           'i',
	'uintptr_t':          'u',
	'ptrdiff_t':          'i',
	'size_t':             'u',
	'ssize_t':            'i',
	}

ui = _cffi.new_primitive_type( 'unsigned int' )
ia = _cffi.new_primitive_type( 'unsigned int' )
pui= _cffi.new_pointer_type( ui )
aui = _cffi.new_array_type(  pui, 16 )

s1 = _cffi.new_struct_type( 's1' )
u1 = _cffi.new_union_type( 'u1' )

ps1= _cffi.new_pointer_type( s1 )
pu1= _cffi.new_pointer_type( s1 )

_cffi.complete_struct_or_union( s1, [
       (_k,_w) for _k,_w in locals().items() if _k[0] not in '_su'
      ], None, 128,  ) 

_cffi.complete_struct_or_union( u1, [
       (_k,_w) for _k,_w in locals().items() if _k[0] not in '_su'
      ] ) 



for a,b in locals().items():
	if a[0] != '_':
		print( a,':',b)
		for k in dir(b):
			print( '    ', k,':', getattr( b, k ))
			
		for f in ['sizeof', 'alignof' ]:
			print( '    ',f,'():',getattr(_cffi,f)( b ) )

