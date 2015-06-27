#ifndef _MERGE_H_
#define _MERGE_H_

#include "intstream.h"
#include "mergeable.h"

int merge(IntStream, IntStream, IntStream);
int pick_lowest(Mergeable, Mergeable, int *);

#endif
