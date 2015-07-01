
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "integer_file_stream.h"

int MAX_INTEGER_DIGITS = 9;

int read_int_from_file(void * instance, int * result) {
    IntegerFileStream input = instance;
    char c;
    int ci; 
    int d;
    int i;
    int temp;

    temp = 0;
    for (i = 0; i < MAX_INTEGER_DIGITS; i++) {
        ci = fgetc(input->file_ptr);
        if (ci == EOF) {
            return 0;
        }
        c = ci;
        if (c == '\n') {
            if (i) {
                *result = temp;
                return 1;
            } else {
                printf("Blank line\n");
                return 0;
            }
        }
        d = c - '0';
        temp = temp * 10 + d;
    }
    printf("Integer too big\n");
    return 0;
}

int write_int_to_file(void * instance, int output) {
    IntegerFileStream self = instance;
    int how_many_chars_written = fprintf(self->file_ptr, "%d\n", output);

    if (how_many_chars_written <= 0) {
        return 0;
    }
    return 1;
}

IntegerFileStream new_integer_file_stream(char * file, int should_create) {
    IntegerFileStream self = malloc(sizeof(struct integer_file_stream));
    FILE * fp = NULL;

    if (!self) {
        return NULL;
    }
    if (should_create) {
        fp = fopen(file, "w+");
    } else {
        fp = fopen(file, "r+");
    }
    if (fp == NULL) {
        printf("Cannot open file %s: %s\n", file, strerror(errno));
        free(self);
        exit(1);
    }
    self->file_ptr = fp;
    self->file_name = file;
    return self;
}

void print_int_file(void * instance) {
}

void reset_integer_file_stream(void * instance) {
    IntegerFileStream self = instance;

    rewind(self->file_ptr);
}

void destroy_integer_file_stream(void * instance) {
    IntegerFileStream self = instance;

    fclose(self->file_ptr);
    free(self);
}
