#include"utils.h"
// Please remove it later...
#include "nlogn_complexity.h"
#include "quadratic_complexity.h"

long long int ctr_compare = 0;
long long int ctr_assign = 0;
long long int ctr_recursion_depth = 0;
long long int ctr_recursion_call = 0;

void clear_counters() {
    ctr_compare = 0;
    ctr_assign = 0;
    ctr_recursion_depth = 0;
    ctr_recursion_call = 0;
}

void print_parameters(double dt) {
    printf( "Time taken          : %.8fs\n"
            "Comparisons         : %lld\n"
            "Assignments         : %lld\n"
            "Max Recursion Depth : %lld\n"
            "Recursive Calls     : %lld\n\n",
            dt, ctr_compare, ctr_assign, ctr_recursion_depth, ctr_recursion_call);
}

void assign(int* a, int* b) {
    ctr_assign++;
    *a = *b;
}

void swap (int* a,int *b) {
    int tmp;
    assign(&tmp, a);
    assign(a, b);
    assign(b, &tmp);
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
    for (int i = 1; i < size; i++)
        if (array[i-1] > array[i]) {
            printf("Oops: %d > %d is false\n", array[i-1], array[i]);
            return false;
        }
    return true;
}

double test_sort(Sort sort, int* array, int size) {
    time_t begin = clock();
    sort(array, size);
    time_t end = clock();

    double dt = (end - begin) / (double) CLOCKS_PER_SEC;

    if (!is_sorted(array, size)) {
        print_array(array, size);
        printf("\nAs you can see, it is not sorted...\nI'll interrupt it here just to get your attention\n");
        exit(0);
    }
    return dt;
}

void print_table (long long int** data) {
    printf( "                    |    Quick    |    Merge    |    Bubble   |  Selection  |  Insertion\n"
            "Time Taken          | %10lfs | %10lfs | %10lfs | %10lfs | %10lfs \n"
            "Comparisons         | %11lld | %11lld | %11lld | %11lld | %11lld \n"
            "Assignments         | %11lld | %11lld | %11lld | %11lld | %11lld \n"
            "Max Recursion Depth | %11lld | %11lld | %11lld | %11lld | %11lld \n"
            "Recursive Calls     | %11lld | %11lld | %11lld | %11lld | %11lld \n",
            *(double*)&data[0][0], *(double*)&data[1][0], *(double*)&data[2][0], *(double*)&data[3][0], *(double*)&data[4][0], // Must cast it back so it uses the right float register
            data[0][1], data[1][1], data[2][1], data[3][1], data[4][1],
            data[0][2], data[1][2], data[2][2], data[3][2], data[4][2],
            data[0][3], data[1][3], data[2][3], data[3][3], data[4][3],
            data[0][4], data[1][4], data[2][4], data[3][4], data[4][4]
          );
}

void benchmark (int* array, int size) {
    printf( "Benchmark mode\n"
            "Sorting algorithms available:\n"
            "\tQuick Sort\n"
            "\tMerge Sort\n"
            "\tBubble Sort\n"
            "\tSelection Sort\n"
            "\tInsertion Sort\n"
            "Results:\n"
            );
    // Aloca matrix de dados nº Sorts x nº métricas
    long long int** data = (long long int**) calloc(5, sizeof(long long int*));
    for (int i = 0; i < 5; i++)
        data[i] = (long long int*) calloc(5, sizeof(long long int));

    // Collect data
    double dt;
    Sort sort;
    int* array_copy;
    for (int i = 0; i < 5; i++) {
        array_copy = copy_array(array, size);
        switch (i) {
        case 0: default:
            sort = quick_sort;
            break;
        case 1:
            sort = merge_sort;
            break;
        case 2:
            sort = bubble_sort;
            break;
        case 3:
            sort = selection_sort;
            break;
        case 4:
            sort = insertion_sort;
            break;
        }
        // Store data
        dt = test_sort(sort, array, size);
        data[i][0] = *(long long int*)&dt; // Just so it works; it's lazy, I know
        data[i][1] = ctr_compare;
        data[i][2] = ctr_assign;
        data[i][3] = ctr_recursion_depth;
        data[i][4] = ctr_recursion_call;
        clear_counters();
        free(array_copy);
    }
    print_table(data);
}

