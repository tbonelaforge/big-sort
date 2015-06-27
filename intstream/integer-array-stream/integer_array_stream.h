#ifndef _INTEGER_ARRAY_STREAM_H
#define _INTEGER_ARRAY_STREAM_H

struct integer_array_stream {
    int * elements;
    int how_many_elements;
    int read_position;
    int write_position;
};

typedef struct integer_array_stream * IntegerArrayStream;

IntegerArrayStream new_integer_array_stream(int);
int read_int_from_array(void *, int *);
int write_int_to_array(void *, int);
void reset_integer_array_stream(void *);
void print_int_array(void *);
void destroy_integer_array_stream(void *);

#endif
