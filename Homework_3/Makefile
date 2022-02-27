all: static dynamic 
	static
	dynamic


static: test_static.c matrix_static.c matrix_static.h
	gcc test_static.c matrix_static.c -o static_matrix_test

dynamic: test_dynamic.c matrix_dynamic.c matrix_dynamic.h  
	gcc test_dynamic.c matrix_dynamic.c -o dynamic_matrix_test

clean:
	rm static_matrix_test
	rm dynamic_matrix_test
