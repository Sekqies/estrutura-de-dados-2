#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

extern long long int ctr_compare;
extern long long int ctr_assign;
extern long long int ctr_recursion_depth;
extern long long int ctr_recursion_call;

typedef void (*Sort)(int*, int);

void clear_counters();
void print_parameters(double dt);
void assign(int* a, int* b);
void swap (int* a,int *b);
int compare_l(int a, int b);
int compare_le(int a, int b);
int min (int a, int b);
int* copy_array (int* array, int size);
void print_array(int* array, int size);
bool is_sorted (int* array, int size);
double test_sort(Sort sort, int* array, int size);
void print_table (long long int** data);
void benchmark (int* array, int size);
