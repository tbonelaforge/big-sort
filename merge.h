#ifndef _MERGE_H_
#define _MERGE_H_

#include "intstream.h"
#include "mergeable.h"
#include "sortable.h"

extern const int MAX_BUFFER_SIZE;

int merge_sort_in_place(int *, int);
int merge_sort_chunks(struct sortable, int);
void cleanup_sortable(struct sortable);
int merge(IntStream, IntStream, IntStream);
int pick_lowest(Mergeable, Mergeable, int *);

#endif
