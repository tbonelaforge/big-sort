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

int main() {
    printf("About to test array_array_array\n");
    test_array_array_array();
    printf("About to test_array_file\n");
    test_array_array_file();
}
