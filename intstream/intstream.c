
#include <stdlib.h>

#include "intstream.h"
#include "integer_array_stream.h"
#include "integer_file_stream.h"

int read_int_stream(IntStream s, int * result) {
    ptr2reader read = s->read;
    void * implementation = s->implementation;

    return (*read)(implementation, result);
}

int write_int_stream(IntStream s, int output) {
    ptr2writer write = s->write;
    void * implementation = s->implementation;

    return (*write)(implementation, output);
}

void print_int_stream(IntStream s) {
    ptr2printer print = s->print;
    void * implementation = s->implementation;

    (*print)(implementation);
}

IntStream new_int_stream_from_array(int * array, int how_many_elements) {
    IntegerArrayStream impl = new_integer_array_stream(how_many_elements);
    IntStream self = NULL;
    int i;

    if (!impl) {
        return NULL;
    }
    self = malloc(sizeof(struct intstream));
    if (!self) {
        destroy_integer_array_stream((void *) impl);
        return NULL;
    }
    self->read = &read_int_from_array;
    self->write = &write_int_to_array;
    self->print = &print_int_array;
    self->reset = &reset_integer_array_stream;
    self->destroy = &destroy_integer_array_stream;
    self->implementation = impl;
    for (i = 0; i < how_many_elements; i++) {
        write_int_stream(self, array[i]);
    }
    return self;
}

IntStream new_int_stream_for_array() {
    IntegerArrayStream impl = new_blank_integer_array_stream();
    IntStream self = NULL;
    int i;

    if (!impl) {
        return NULL;
    }
    self = malloc(sizeof(struct intstream));
    if (!self) {
        destroy_integer_array_stream((void *) impl);
        return NULL;
    }
    self->read = &read_int_from_array;
    self->write = &write_int_to_array;
    self->print = &print_int_array;
    self->reset = &reset_integer_array_stream;
    self->destroy = &destroy_integer_array_stream;
    self->implementation = impl;
    return self;
}

IntStream new_int_stream_from_file(char * file) {
    IntegerFileStream impl = new_integer_file_stream(file);
    IntStream self = NULL;
    int i;

    if (!impl) {
        return NULL;
    }
    self = malloc(sizeof(struct intstream));
    if (!self) {
        destroy_integer_file_stream((void *) impl);
        return NULL;
    }
    self->read = &read_int_from_file;
    self->write = &write_int_to_file;
    self->print = &print_int_file;
    self->reset = &reset_integer_file_stream;
    self->destroy = &destroy_integer_file_stream;
    self->implementation = impl;
    return self;
}

void destroy_int_stream(IntStream self) {
    ptr2destructor destroy = self->destroy;
    void * implementation = self->implementation;

    (*destroy)(implementation);
    free(self);
}

void reset_int_stream(IntStream self) {
    ptr2resetter reset = self->reset;
    void * implementation = self->implementation;
    (*reset)(implementation);
}


void hook_int_stream_to_array(IntStream stream, int * array, int n, int i, int j) {
    void * impl = stream->implementation;
    hook_integer_array_stream_to_array(impl, array, n, i, j);

}

