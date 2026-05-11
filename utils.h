#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

extern int ctr_compare;
extern int ctr_assign;
extern int ctr_recursion_depth;
extern int ctr_recursion_call;

typedef void (*Sort)(int*, int);

void clear_counters();
void print_parameters(float dt);
void assign(int* a, int* b);
void swap (int* a,int *b);
int compare_l(int a, int b);
int compare_le(int a, int b);
int min (int a, int b);
int* copy_array (int* array, int size);
void print_array(int* array, int size);
bool is_sorted (int* array, int size);
float test_sort(Sort sort, int* array, int size);
void benchmark (int* array, int size);
