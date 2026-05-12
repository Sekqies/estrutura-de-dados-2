#include "headers/sorts_nlogn.h"
#include "headers/sorts_quadratic.h"
#include "headers/utils.h"
#include "headers/input.h"
#include "headers/output.h"

int main (int argc, char** argv) {
    // Variáveis
    int* array;
    int size = 0;
    char* input = NULL; // PATH do arquivo de entrada
    int mode = 0; // Modo de operação: 0 = adaptativo, 1 = benchmark, 2 = quick, 3 = merge, 4 = bubble, 5 = selection, 6 = insertion

    // Determina operação de acordo com as flags
    deal_with_flags(argc, argv, &input, &mode, &size);

    // Lê array
    if (input == NULL || strcmp(input, "-") == 0)
        array = read_array(&size);
    else
        array = read_file(input, &size);

    // printf("Array size: %d\n", size);
    // print_array(array, size);



    if (mode == 1) {
        // printf("#Todo\n");
        // exit(0);
        benchmark(array, size);
    }
    else {
        if (mode == 0) {
            printf("#Todo\n");
            mode = 2; // Sends to Quick Sort
            printf("Algoritmo escolhido pela heurística: ");
        }
        Sort sort;
        char* name;
        switch (mode) {
        case 2:
            sort = quick_sort;
            name = "Quick Sort";
            break;
        case 3:
            sort = merge_sort;
            name = "Merge Sort";
            break;
        case 4:
            sort = bubble_sort;
            name = "Bubble Sort";
            break;
        case 5:
            sort = selection_sort;
            name = "Selection Sort";
            break;
        case 6:
            sort = insertion_sort;
            name = "Insertion Sort";
            break;
        }
        printf("%s\n", name);
        float dt = test_sort(sort, array, size);
        print_parameters(dt);
        clear_counters();
    }
}
