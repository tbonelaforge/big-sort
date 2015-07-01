
#include <stdio.h>
#include <stdlib.h>

#include "intstream.h"
#include "merge.h"

int read_batch(IntStream input, int * A) {
    int how_many_read = 0;

    while ( how_many_read < MAX_BUFFER_SIZE ) {
        if (read_int_stream(input, A + how_many_read)) {
            how_many_read += 1;
        } else {
            break;
        }
    }
    return how_many_read;
}

char * big_sort(char * input_file, char * output_file) {
    IntStream input = NULL;
    IntStream partial1 = NULL;
    IntStream partial2 = NULL;
    IntStream buffer = NULL;
    IntStream temp = NULL;
    int A[MAX_BUFFER_SIZE];
    int n;
    char * result;

    input = new_int_stream_from_file(input_file, 0);
    if (!input) {
        printf("Unable to create the input stream!\n");
        return NULL;
    }
    partial1 = new_int_stream_from_file("partial1.txt", 1);
    if (!partial1) {
        destroy_int_stream(input);
        printf("Unable to create partial results stream 1\n");
        return NULL;
    }
    partial2 = new_int_stream_from_file("partial2.txt", 1);
    if (!partial2) {
        destroy_int_stream(input);
        destroy_int_stream(partial1);
        printf("Unable to create partial results stream 2\n");
        return NULL;
    }
    buffer = new_int_stream_for_array();
    if (!buffer) {
        destroy_int_stream(input);
        destroy_int_stream(partial1);
        destroy_int_stream(partial2);
        printf("Unable to create buffer stream\n");
        return NULL;
    }
    while ((n = read_batch(input, A)) > 0) {
        merge_sort_in_place(A, n);
        hook_int_stream_to_array(buffer, A, n, 0, n - 1);
        merge(buffer, partial1, partial2);
        reset_int_stream(partial1);
        reset_int_stream(partial2);
        temp = partial1;
        partial1 = partial2;
        partial2 = temp;
    }
    result = get_filename(partial1);
    rename(result, output_file);
    return output_file;
}
