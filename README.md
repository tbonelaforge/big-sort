Sorting Sets of integers which are too big to fit in memory.

Basic strategy is to read a chunk of a huge file into memory, sort the chunk, then merge the chunk with a file of partial results.