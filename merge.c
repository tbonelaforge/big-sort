
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "merge.h"

const int MAX_BUFFER_SIZE = 10;

int BUFFER[MAX_BUFFER_SIZE];

int compare(int x, int y) {
    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    }
    return 0;
}

int merge(IntStream a, IntStream b, IntStream output) {
    int how_many_merged = 0;
    struct mergeable left = { a, 0, 0 };
    struct mergeable right = { b, 0, 0 };
    int x;

    while (1) {
        prepare_mergeable_next(&left);
        prepare_mergeable_next(&right);
        if (!pick_lowest(&left, &right, &x)) {
            return how_many_merged;
        }
        if (write_int_stream(output, x)) {
            how_many_merged += 1;
        } else {
            printf("Not able to write to output stream\n");
            return 0;
        }
    }
}

int pick_lowest(Mergeable left, Mergeable right, int * result) {
    Mergeable lowest = NULL;
    int comparison;

    if (!left->has_next && !right->has_next) {
        return 0;
    }
    if (!left->has_next && right->has_next) {
        lowest = right;
    } else if (!right->has_next && left->has_next) {
        lowest = left;
    } else {
        comparison = compare(left->next, right->next);
        lowest = ( comparison <= 0 ) ? left : right;
    }
    *result = lowest->next;
    lowest->has_next = 0;
    return 1;
}

int merge_sort_in_place(int * A, int N) {
    IntStream a_stream = new_int_stream_for_array();
    IntStream b_stream = new_int_stream_for_array();
    IntStream c_stream = new_int_stream_for_array();
    struct sortable s = {
        A,
        N - 1,
        BUFFER,
        a_stream,
        b_stream,
        c_stream
    };
    int p = 1;
    int * swap = NULL;
    int i;

    while (pow(2, p - 1) <= N) {
        if (!merge_sort_chunks(s, p)) {
            cleanup_sortable(s);
            return 0;
        }
        p += 1;
        swap = s.elements;
        s.elements = s.temp;
        s.temp = swap;
    }
    for (i = 0; i < N; i++) {
        A[i] = s.elements[i];
    }
    cleanup_sortable(s);
    return 1;
}




int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int merge_sort_chunks(struct sortable s, int p) {
    int k = 0;
    int i_0, i_1, j_0, j_1;
    int * swap;

    hook_int_stream_to_array(s.c_stream, s.temp, s.last_index + 1, 0, s.last_index);
    reset_int_stream(s.c_stream);
    while (k * pow(2, p) <= s.last_index) {
        i_0 = k * pow(2, p);
        i_1 = min(s.last_index, i_0 + pow(2, p - 1) - 1);
        j_0 = i_0 + pow(2, p - 1);
        j_1 = min(s.last_index, (k + 1) * pow(2, p) - 1);
        hook_int_stream_to_array(s.a_stream, s.elements, s.last_index + 1, i_0, i_1);
        hook_int_stream_to_array(s.b_stream, s.elements, s.last_index + 1, j_0, j_1);
        merge(s.a_stream, s.b_stream, s.c_stream);
        k += 1;
    }
    return 1;
}

void cleanup_sortable(struct sortable s) {
    free(s.a_stream);
    free(s.b_stream);
    free(s.c_stream);
}

void print_sortable(struct sortable s) {
    int i;

    for (i = 0; i <= s.last_index; i++) {
        printf("%d", s.elements[i]);
        if (i < s.last_index) {
            printf(", ");
        }
    }
    printf("\n");
}
