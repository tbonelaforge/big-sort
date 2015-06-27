
#include <stdio.h>

#include "mergeable.h"
#include "intstream.h"

void prepare_mergeable_next(Mergeable m) {
    int n;

    if (m->has_next) {
        return;
    }
    if (read_int_stream(m->source, &n)) {
        m->has_next = 1;
        m->next = n;
    }
}
