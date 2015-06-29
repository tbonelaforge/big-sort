
#include <stdlib.h>
#include <stdio.h>

#include "integer_array_stream.h"

void initialize_elements(IntegerArrayStream self) {
    int i;

    for (i = 0; i < self->how_many_elements; i++) {
        self->elements[i] = 0;
    }
}

IntegerArrayStream new_integer_array_stream(int how_many_elements) {
    int * elements = malloc(how_many_elements * sizeof(int));
    IntegerArrayStream self = NULL;

    if (!elements) {
        return NULL;
    }
    self = malloc(sizeof(struct integer_array_stream));
    if (!self) {
        free(elements);
        return NULL;
    }
    self->elements = elements;
    self->how_many_elements = how_many_elements;
    self->read_position = 0;
    self->write_position = 0;
    initialize_elements(self);
    return self;
}

int read_int_from_array(void * instance, int * result) {
    IntegerArrayStream input = instance;
    int position = input->read_position;
    int temp;

    if (position >= input->write_position ||
        position >= input->how_many_elements) {
        return 0;
    }
    temp = input->elements[position];
    input->read_position += 1;
    *result = temp;
    return 1;
}

int write_int_to_array(void * instance, int output) {
    IntegerArrayStream self = instance;
    int position = self->write_position;

    if (position >= self->how_many_elements) {
        return 0;
    }
    self->elements[position] = output;
    self->write_position += 1;
    return 1;
}

void reset_integer_array_stream(void * instance) {
    IntegerArrayStream self = instance;

    self->read_position = 0;
    self->write_position = 0;
}

void print_int_array(void * instance) {
    IntegerArrayStream self = instance;
    int i;

    for (i = 0; i < self->how_many_elements; i++) {
        printf("%d\n", self->elements[i]);
    }
    printf("read_position: %d, write_position: %d\n", self->read_position, self->write_position);
}

void destroy_integer_array_stream(void * instance) {
    IntegerArrayStream self = instance;
    if (self->elements) {
        free(self->elements);
    }
    free(self);
}

IntegerArrayStream new_blank_integer_array_stream() {
    IntegerArrayStream self = malloc(sizeof(struct integer_array_stream));
    if (!self) {
        return NULL;
    }
    self->elements = NULL;
    self->how_many_elements = 0;
    self->read_position = 0;
    self->write_position = 0;
    return self;
}

void hook_integer_array_stream_to_array(void * impl, int * array, int n, int i, int j) {
    struct integer_array_stream * self = impl;

    self->elements = array;
    self->how_many_elements = n;
    self->read_position = i;
    self->write_position = j + 1;
}
