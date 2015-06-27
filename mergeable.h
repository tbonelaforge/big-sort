#ifndef _MERGEABLE_H_
#define _MERGEABLE_H_

#include "intstream.h"

struct mergeable {
    IntStream source;
    int has_next;
    int next;
};

typedef struct mergeable * Mergeable;

void prepare_mergeable_next(Mergeable);

#endif
