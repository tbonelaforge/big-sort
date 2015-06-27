#include <stdio.h>

#include "integer_array_stream.h"

int main() {
    int test_ints[] = {
        1,
        23,
        456
    };
    int N = 3;
    struct integer_array_stream test = {
        test_ints,
        3,
        0
    };
    int code;
    int test_int;

    printf("About to try and read an integer from the array:\n");
    code = read_int_from_array((void *) &test, &test_int);
    printf("The result of read_int_from_array is %d\n", code);
    printf("After reading the integer from the array, the test_int is: %d\n", test_int);

    printf("About to try and read an integer from the array:\n");
    code = read_int_from_array((void *) &test, &test_int);
    printf("The result of read_int_from_array is %d\n", code);
    printf("After reading the integer from the array, the test_int is: %d\n", test_int);

    printf("About to try and read an integer from the array:\n");
    code = read_int_from_array((void *) &test, &test_int);
    printf("The result of read_int_from_array is %d\n", code);
    printf("After reading the integer from the array, the test_int is: %d\n", test_int);

    printf("About to try and read an integer from the array:\n");
    code = read_int_from_array((void *) &test, &test_int);
    printf("The result of read_int_from_array is %d\n", code);
    printf("After reading the integer from the array, the test_int is: %d\n", test_int);

}
