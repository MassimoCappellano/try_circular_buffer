test_p: main.c circular_buffer.c circular_buffer.h data_circular_buffer.h
	cc main.c circular_buffer.c -o test_p

clean:
	rm test_p
