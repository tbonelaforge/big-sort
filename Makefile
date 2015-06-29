all: intstream mergeable.o mergetest.bin 

mergetest.bin: mergetest.c merge.o mergeable.o merge.h intstream
	gcc -I ./intstream/ mergetest.c merge.o mergeable.o intstream/intstream.o intstream/integer-array-stream/integer_array_stream.o intstream/integer-file-stream/integer_file_stream.o -o mergetest.bin

merge.o: merge.c merge.h
	gcc -I ./intstream/ -I ./mergeable/ -c merge.c -o merge.o

.PHONY: intstream

intstream:
	cd ./intstream; make

mergeable.o: mergeable.c mergeable.h
	gcc -I ./intstream/ -c mergeable.c -o mergeable.o

