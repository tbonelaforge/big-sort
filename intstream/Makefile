all: integer-array-stream integer-file-stream intstream.o

intstream.o: intstream.c intstream.h integer-array-stream integer-file-stream
	gcc -c -I ./integer-array-stream/ -I ./integer-file-stream/ intstream.c -o intstream.o

.PHONY: integer-array-stream

integer-array-stream:
	cd ./integer-array-stream; make

.PHONY: integer-file-stream
	cd ./integer-file-stream; make

integer-file-stream:
	cd ./integer-file-stream; make


