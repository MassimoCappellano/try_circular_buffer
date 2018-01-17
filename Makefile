
all: test_suite_multi test_suite_simple

# use synchronized circular buffer
test_suite_multi: test_suite_multi.c circular_buffer_sync.c circular_buffer.h data_circular_buffer.h
	cc test_suite_multi.c circular_buffer_sync.c -lpthread -o test_suite_multi

# use simple circular buffer
test_suite_simple: test_suite_simple.c circular_buffer.c circular_buffer.h data_circular_buffer.h
	cc test_suite_simple.c circular_buffer.c -o test_suite_simple

clean:
	rm test_suite_multi test_suite_simple
