all: integer_file_stream_test.bin

integer_file_stream_test.bin: integer_file_stream_test.c integer_file_stream.o integer_file_stream.h
	gcc -I ./ integer_file_stream_test.c integer_file_stream.o -o integer_file_stream_test.bin

integer_file_stream.o: integer_file_stream.c integer_file_stream.h
	gcc -I ./ -c integer_file_stream.c -o integer_file_stream.o
