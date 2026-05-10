// Make header files
// #include"quadratic_complexity.c"
#include"nlogn_complexity.h"
#include"quadratic_complexity.h"
#include"utils.h"
#include<time.h>

void test_quadratic_sort(void (*sort)(int*, int), int* array, int size) {
    int* array_cp = copy_array(array, size);
    time_t begin = clock();
    (*sort)(array_cp, size);
    time_t end = clock();
    print_array(array_cp, size);
    float dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    if (!is_sorted(array_cp, size)) {
        printf("\n\nAs you can see, it is not sorted...\nI'll interrupt it here just to get your attention\n");
        exit(0);
    }
    free(array_cp);
}

void test_nlogn_sort(void (*sort)(int*, int, int), int* array, int size) {
    int* array_cp = copy_array(array, size);
    time_t begin = clock();
    (*sort)(array_cp, 0, size-1);
    time_t end = clock();
    print_array(array_cp, size);
    float dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    if (!is_sorted(array_cp, size)) {
        printf("\n\nAs you can see, it is not sorted...\nI'll interrupt it here just to get your attention\n");
        exit(0);
    }
    free(array_cp);
}

int main() {
    int size = 28;
    int* array;
    time_t begin, end;
    float dt;
    int array1[] = {5, 9, 4, 56, 88, 50, 34, 55, 68, 21, 22, 25, 64, 96, 44, 48, 74, 59, 27, 33, 39, 10, 55, 76, 78, 34, 77, 39};
    int* array2 = malloc(2*size*sizeof(int));
    for (int i = 0; i < size; i++) {
        array2[2*i] = array1[i];
        array2[2*i+1] = array1[i];
    }


    /*---------- Quick Sort ----------*/
    printf("\nQuick Sort:\n");

    test_nlogn_sort(quick_sort, array1, size);
    test_nlogn_sort(quick_sort, array2, 2*size);

    /*---------- Merge Sort ----------*/
    printf("\nMerge Sort:\n");

    test_nlogn_sort(merge_sort, array1, size);
    test_nlogn_sort(merge_sort, array2, 2*size);

    /*---------- Bubble Sort ----------*/
    printf("\nBubble Sort:\n");

    test_quadratic_sort(bubble_sort, array1, size);
    test_quadratic_sort(bubble_sort, array2, 2*size);

    /*---------- Selection Sort ----------*/
    printf("\nSelection Sort:\n");

    test_quadratic_sort(selection_sort, array1, size);
    test_quadratic_sort(selection_sort, array2, 2*size);

    /*---------- Insertion Sort ----------*/
    printf("\nInsertion Sort:\n");

    test_quadratic_sort(insertion_sort, array1, size);
    test_quadratic_sort(insertion_sort, array2, 2*size);
}
