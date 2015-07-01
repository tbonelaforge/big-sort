#ifndef _INTSTREAM_H_
#define _INTSTREAM_H_

typedef int (*ptr2reader)(void *, int *);
typedef int (*ptr2writer)(void *, int);
typedef void (*ptr2printer)(void *);
typedef void (*ptr2destructor)(void *);
typedef void (*ptr2resetter)(void *);

struct intstream {
    ptr2reader read;
    ptr2writer write;
    ptr2printer print;
    ptr2resetter reset;
    ptr2destructor destroy;
    void * implementation;
};

typedef struct intstream * IntStream;

int read_int_stream(IntStream, int *);
int write_int_stream(IntStream, int);
void reset_int_stream(IntStream);
void print_int_stream(IntStream);
void destroy_int_stream(IntStream);
IntStream new_int_stream_from_array(int *, int);
IntStream new_int_stream_from_file(char *, int);
char * get_filename(IntStream);
IntStream new_int_stream_for_array();
void hook_int_stream_to_array(IntStream, int *, int, int, int);

#endif
