all: intstream mergeable.o mergetest.bin big_sort_test.bin

mergetest.bin: mergetest.c merge.o mergeable.o merge.h intstream
	gcc -I ./intstream/ mergetest.c merge.o mergeable.o intstream/intstream.o intstream/integer-array-stream/integer_array_stream.o intstream/integer-file-stream/integer_file_stream.o -o mergetest.bin

merge.o: merge.c merge.h
	gcc -I ./intstream/ -I ./mergeable/ -c merge.c -o merge.o

big_sort_test.bin: big_sort_test.c big_sort.o merge.o mergeable.o merge.h intstream
	gcc -I ./intstream/ big_sort_test.c merge.o mergeable.o intstream/intstream.o intstream/integer-array-stream/integer_array_stream.o intstream/integer-file-stream/integer_file_stream.o big_sort.o -o big_sort_test.bin

big_sort.o: big_sort.h big_sort.c
	gcc -I ./intstream/ -c big_sort.c -o big_sort.o

.PHONY: intstream

intstream:
	cd ./intstream; make

mergeable.o: mergeable.c mergeable.h
	gcc -I ./intstream/ -c mergeable.c -o mergeable.o

