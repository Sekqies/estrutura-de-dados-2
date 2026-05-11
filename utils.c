#include"utils.h"

int ctr_compare = 0;
int ctr_assign = 0;
int ctr_recursion_depth = 0;
int ctr_recursion_call = 0;

void clear_counters() {
    ctr_compare = 0;
    ctr_assign = 0;
    ctr_recursion_depth = 0;
    ctr_recursion_call = 0;
}

void print_parameters(float dt) {
    printf( "Time taken          : %.8fs\n"
            "Comparisons         : %d\n"
            "Assignments         : %d\n"
            "Max Recursion Depth : %d\n"
            "Recursive Calls     : %d\n\n",
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

float test_sort(Sort sort, int* array, int size) {
    time_t begin = clock();
    (*sort)(array, size);
    time_t end = clock();

    float dt = (end - begin) / (float) CLOCKS_PER_SEC;

    if (!is_sorted(array, size)) {
        print_array(array, size);
        printf("\nAs you can see, it is not sorted...\nI'll interrupt it here just to get your attention\n");
        exit(0);
    }
    return dt;
}

void print_table (int** data) {
    printf( "                    | Quick | Merge | Bubble | Selection | Insertion\n"
            "Time Taken          | %8f | %8f | %8f | %8f | %8f \n"
            "Comparisons         | %8d | %8d | %8d | %8d | %8d \n"
            "Assignments         | %8d | %8d | %8d | %8d | %8d \n"
            "Max Recursion Depth | %8d | %8d | %8d | %8d | %8d \n"
            "Recursive Calls     | %8d | %8d | %8d | %8d | %8d \n",
            data[0][0], data[1][0], data[2][0], data[3][0], data[4][0],
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
            "Results:\n\n"
            );
    // Aloca matrix de dados nº Sorts x nº métricas
    for (int i = 0; i < 5; i++) {
        i = 10;
    }
}

