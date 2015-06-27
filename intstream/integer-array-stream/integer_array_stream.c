
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
}

void destroy_integer_array_stream(void * instance) {
    IntegerArrayStream self = instance;
    free(self->elements);
    free(self);
}
