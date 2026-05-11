#include "quadratic_complexity.h"

void bubble_sort (int* array, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size; ++j) {
            if (compare_l(array[j], array[j-1])) {
                swap(&array[j], &array[j-1]);
            } 
        }
    }
}

void selection_sort (int* array, int size) {
    for (int i = 0; i < size-1; ++i) {
        int smallest_index = i;
        for (int j = i+1; j < size; ++j) {
            if (compare_l(array[j], array[smallest_index]))
                smallest_index = j;
        }
        swap(&array[i], &array[smallest_index]);
    }
}

void insertion_sort (int* array, int size) {
    for (int i = 1; i < size; ++i) {
        int j = i-1;
        int key;
        assign(&key, &array[i]);
        while (j >= 0 && compare_l(key, array[j])) {
            assign(&array[j+1], &array[j]);
            j--;
        }
        assign(&array[j+1], &key);
    }
}
