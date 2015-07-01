
#include <stdio.h>

#include "big_sort.h"

void test_big_sort1() {
    printf("About to test big-sort...\n");
    char * inputfile = "big-sort-test-input.txt";
    char * outputfile = big_sort(inputfile, "big-sort-test-output.txt");
    printf("The resulting file is: %s\n", outputfile);
}

void test_big_sort2() {
    printf("About to test big-sort on a bigger file...\n");
    char * inputfile = "big-sort-test-input2.txt";
    char * outputfile = big_sort(inputfile, "big-sort-test-output2.txt");
    printf("The resulting file is: %s\n", outputfile);
}

void test_big_sort3() {
    printf("About to test big-sort on an even bigger file...\n");
    char * inputfile = "big-sort-test-input3.txt";
    char * outputfile = big_sort(inputfile, "big-sort-test-output3.txt");
    printf("The resulting file is: %s\n", outputfile);
}

int main() {
    test_big_sort1();
    test_big_sort2();
    test_big_sort3();
}
