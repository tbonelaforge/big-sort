
#include <stdio.h>

#include "big_sort.h"

int main() {
    printf("About to test big-sort...\n");
    char * inputfile = "big-sort-test-input.txt";
    char * outputfile = big_sort(inputfile);
    printf("The resulting file is: %s\n", outputfile);
}
