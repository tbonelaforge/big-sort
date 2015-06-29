#ifndef _SORTABLE_H_
#define _SORTABLE_H_

#include "intstream.h"

struct sortable {
    int * elements;
    int last_index;
    int * temp;
    IntStream a_stream;
    IntStream b_stream;
    IntStream c_stream;
};

void print_sortable(struct sortable);

#endif
