#include"utils.h"

void swap (int* a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int min (int a, int b){
    return a>b? a : b;
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
