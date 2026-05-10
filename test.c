// Make header files
// #include"quadratic_complexity.c"
#include"nlogn_complexity.h"
#include"quadratic_complexity.h"
#include<time.h>


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

    array = copy_array(array1, size);
    begin = clock();
    quick_sort(array, 0, size-1);
    end = clock();
    print_array(array, size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    array = copy_array(array2, 2*size);
    begin = clock();
    quick_sort(array, 0, 2*size-1);
    end = clock();
    print_array(array, 2*size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    /*---------- Merge Sort ----------*/
    printf("\nMerge Sort:\n");

    array = copy_array(array1, size);
    begin = clock();
    merge_sort(array, 0, size-1);
    end = clock();
    print_array(array, size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    array = copy_array(array2, 2*size);
    begin = clock();
    merge_sort(array, 0, 2*size-1);
    end = clock();
    print_array(array, 2*size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    /*---------- Bubble Sort ----------*/
    printf("\nBubble Sort:\n");

    array = copy_array(array1, size);
    begin = clock();
    bubble_sort(array, size);
    end = clock();
    print_array(array, size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    array = copy_array(array2, 2*size);
    begin = clock();
    bubble_sort(array, 2*size);
    end = clock();
    print_array(array, 2*size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    /*---------- Selection Sort ----------*/
    printf("\nSelection Sort:\n");

    array = copy_array(array1, size);
    begin = clock();
    selection_sort(array, size);
    end = clock();
    print_array(array, size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    array = copy_array(array2, 2*size);
    begin = clock();
    selection_sort(array, 2*size);
    end = clock();
    print_array(array, 2*size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    /*---------- Insertion Sort ----------*/
    printf("\nInsertion Sort:\n");

    array = copy_array(array1, size);
    begin = clock();
    insertion_sort(array, size);
    end = clock();
    print_array(array, size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);

    array = copy_array(array2, 2*size);
    begin = clock();
    insertion_sort(array, 2*size);
    end = clock();
    print_array(array, 2*size);
    dt = (end - begin) / (float) CLOCKS_PER_SEC;
    printf("Time taken: %.8fs\n", dt);
    free(array);
}
