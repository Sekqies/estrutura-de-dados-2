#include"utils.h"

int ctr_compare = 0;
int ctr_assign = 0;
int ctr_swap = 0;
int ctr_recursion_depth = 0;
int ctr_recursion_call = 0;

void clear_counters() {
    ctr_compare = 0;
    ctr_assign = 0;
    ctr_swap = 0;
    ctr_recursion_depth = 0;
    ctr_recursion_call = 0;
}

void print_counters() {
    printf( "Comparisons        : %d\n"
            "Assignments        : %d\n"
            "Swaps              : %d\n"
            "Max Recursion Depth: %d\n"
            "Recursive Calls    : %d\n\n",
            ctr_compare, ctr_assign, ctr_swap, ctr_recursion_depth, ctr_recursion_call);
}

void assign(int* a, int* b) {
    ctr_assign++;
    *a = *b;
}

void swap (int* a,int *b) {
    ctr_swap++;
    ctr_assign += 3;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int compare_l (int a, int b) {
    ctr_compare++;
    return a < b;
}

int compare_le (int a, int b) {
    ctr_compare++;
    return a <= b;
}

int min (int a, int b){
    return a > b ? a : b;
}

int* copy_array (int* array, int size) {
    int* array2 = malloc(size*sizeof(int));
    for (int i = 0; i < size; i++)
        array2[i] = array[i];
    return array2;
}

void print_array (int* array, int size) {
    for (int i = 0; i < size-1; i++)
        printf("%d ", array[i]);
    printf("%d\n", array[size-1]);
}

bool is_sorted (int* array, int size) {
    for (int i = 0; i < size; i++)
        if (array[i-1] > array[i])
            return false;
    return true;
}
