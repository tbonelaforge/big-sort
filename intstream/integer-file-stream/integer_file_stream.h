#ifndef _INTEGER_FILE_STREAM_H_
#define _INTEGER_FILE_STREAM_H_

#include <stdio.h>

struct integer_file_stream {
    FILE * file_ptr;
};

typedef struct integer_file_stream * IntegerFileStream;

int read_int_from_file(void *, int *);
int write_int_to_file(void *, int);
void reset_integer_file_stream(void *);
IntegerFileStream new_integer_file_stream(char *);
void print_int_file(void *);
void destroy_integer_file_stream(void *);

#endif
