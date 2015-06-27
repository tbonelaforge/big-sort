
#include <stdio.h>

#include "merge.h"

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
