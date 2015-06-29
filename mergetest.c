#include <stdio.h>

#include "merge.h"
#include "intstream.h"

void test_array_array_array() {
    int a_ints[] = { 1, 3, 5 };
    int a_n = 3;
    int b_ints[] = { 2, 4, 6 };
    int b_n = 3;
    int c_ints[6];
    int c_n = 6;
    
    IntStream a = new_int_stream_from_array(a_ints, a_n);
    IntStream b = new_int_stream_from_array(b_ints, b_n);
    IntStream c = new_int_stream_from_array(c_ints, c_n);
    reset_int_stream(c);
    
    int how_many_merged = merge(a, b, c);

    print_int_stream(c);
    destroy_int_stream(a);
    destroy_int_stream(b);
    destroy_int_stream(c);
}

void test_array_array_file() {
    int a_ints[] = { 1, 3, 5 };
    int a_n = 3;
    int b_ints[] = { 2, 4, 6 };
    int b_n = 3;
    char * c_file = "output.txt";
    
    IntStream a = new_int_stream_from_array(a_ints, a_n);
    IntStream b = new_int_stream_from_array(b_ints, b_n);

    IntStream c = new_int_stream_from_file(c_file);
    reset_int_stream(c);
    int how_many_merged = merge(a, b, c);

    print_int_stream(c);
    printf("Wrote file: %s\n", c_file);
    destroy_int_stream(a);
    destroy_int_stream(b);
    destroy_int_stream(c);
}

void test_array_file_array() {
    int a_ints[] = { 1, 3, 5 };
    int a_n = 3;
    char * b_file = "input.txt";
    int c_ints[6];
    int c_n = 6;
    IntStream a = new_int_stream_from_array(a_ints, a_n);
    IntStream b = new_int_stream_from_file(b_file);
    IntStream c = new_int_stream_from_array(c_ints, c_n);

    reset_int_stream(c);
    int how_many_merged = merge(a, b, c);
    printf("The resulting array is:\n");
    print_int_stream(c);
    destroy_int_stream(a);
    destroy_int_stream(b);
    destroy_int_stream(c);
}

void test_file_array_array() {
    char * a_file = "input.txt";
    int b_ints[] = { 1, 3, 5 };
    int b_n = 3;
    int c_ints[6];
    int c_n = 6;
    IntStream a = new_int_stream_from_file(a_file);
    IntStream b = new_int_stream_from_array(b_ints, b_n);
    IntStream c = new_int_stream_from_array(c_ints, c_n);

    reset_int_stream(c);
    int how_many_merged = merge(a, b, c);
    printf("The resulting array is:\n");
    print_int_stream(c);
    destroy_int_stream(a);
    destroy_int_stream(b);
    destroy_int_stream(c);
}

void test_in_place_merge_sort1() {
    int A[] = { 2, 5, 1, 7, 9, 8, 13 };
    int N = 7;
    int i;

    if (!merge_sort_in_place(A, N)) {
        printf("There was an error merge sorting in place...\n");
    }
    printf("The sorted version is now:\n");
    for (i = 0; i < N; i++) {
        printf("%d\n", A[i]);
    }
}

void test_in_place_merge_sort2() {
    int A[] = { 5, 9, 1, 1, 10, 2, 4, 6, 7 };
    int N = 9;
    int i;

    if (!merge_sort_in_place(A, N)) {
        printf("There was an error merge sorting in place...\n");
    }
    printf("The sorted version is now:\n");
    for (i = 0; i < N; i++) {
        printf("%d\n", A[i]);
    }
}

int main() {
    printf("About to test array_array_array\n");
    test_array_array_array();

    printf("About to test_array_file\n");
    test_array_array_file();

    printf("About to test array_file_array\n");
    test_array_file_array();

    printf("About to test file_array_array\n");
    test_file_array_array();

    printf("About to test in-place merge sort, with an array containing 8 elements...\n");
    test_in_place_merge_sort1();

    printf("About to test in-place merge sort, with an array containing 8 elements...\n");
    test_in_place_merge_sort2();
}
