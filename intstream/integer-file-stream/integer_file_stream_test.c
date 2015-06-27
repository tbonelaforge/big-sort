#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "integer_file_stream.h"

void test_basic_usage() {
    FILE * fp;
    char * testfile = "integer_file_stream_test.txt";
    
    fp = fopen(testfile, "r");
    if (fp == NULL) {
        printf("Cannot open file %s: %s\n", testfile, strerror(errno));
        exit(1);
    }
    struct integer_file_stream test = {
        fp
    };
    int test_int = 0;
    int code;

    printf("\n\nAbout to try and read an integer from the file:\n");
    code = read_int_from_file((void *) &test, &test_int);
    printf("The result of read_int_from_file is %d\n", code);
    printf("After reading the integer from the file, the result is now %d\n", test_int);

    printf("\nAbout to try and read an integer from the file:\n");
    code = read_int_from_file((void *) &test, &test_int);
    printf("The result of read_int_from_file is %d\n", code);
    printf("After reading the integer from the file, the result is now %d\n", test_int);

    printf("\nAbout to try and read an integer from the file:\n");
    code = read_int_from_file((void *) &test, &test_int);
    printf("The result of read_int_from_file is %d\n", code);
    printf("After reading the integer from the file, the result is now %d\n", test_int);

    printf("\nAbout to try and read an integer from the file:\n");
    code = read_int_from_file((void *) &test, &test_int);
    printf("The result of read_int_from_file is %d\n", code);
    printf("After reading the integer from the file, the result is now %d\n", test_int);

    printf("\nAbout to try and read an integer from the file:\n");
    code = read_int_from_file((void *) &test, &test_int);
    printf("The result of read_int_from_file is %d\n", code);
    printf("After reading the integer from the file, the result is now %d\n", test_int);
}

void test_integer_too_big() {
    FILE * fp;
    char * testfile = "integer_file_stream_test_too_big.txt";
    
    fp = fopen(testfile, "r");
    if (fp == NULL) {
        printf("Cannot open file %s: %s\n", testfile, strerror(errno));
        exit(1);
    }
    struct integer_file_stream test = {
        fp
    };
    int test_int = 0;
    int code;
    
    printf("\n\nAbout to try and read an integer from the file:\n");
    code = read_int_from_file((void *) &test, &test_int);
    printf("The result of read_int_from_file is %d\n", code);
    printf("After reading the integer from the file, the result is now %d\n", test_int);
}

int main() {
    test_basic_usage();
    test_integer_too_big();
}

