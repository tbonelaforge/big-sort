all: integer_array_stream_test.bin integer_array_stream.o

integer_array_stream_test.bin: integer_array_stream.o integer_array_stream.h integer_array_stream_test.c
	gcc -I ./ integer_array_stream_test.c integer_array_stream.o -o integer_array_stream_test.bin

integer_array_stream.o: integer_array_stream.c
	gcc -I ./ -c integer_array_stream.c -o integer_array_stream.o
