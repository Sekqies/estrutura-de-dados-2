#include "nlogn_complexity.h"
#include "quadratic_complexity.h"
#include "utils.h"
#include <time.h>
#include <string.h>

// Transforma alfabeto maiúsculo em minúsculo
void to_lowercase (char* str) {
    for (int i = 0; str[i] != 0; i++)
        if (str[i] >= 0x41 && str[i] <= 0x5a)
            str[i] += 0x20;
}

// Lida com as flags da linha de comando
void deal_with_flags (int argc, char** argv, char** input, int* mode, int* size) {
    bool error = false;
    bool help = false;
    for (int i = 1; i < argc; i++) {
        // Ignora capitalização se a flag for --[...]
        if (argv[i][1] == '-')
            to_lowercase(argv[i]);
        // Interpreta flags
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            help = true;
            break;
        } else if (strcmp(argv[i], "--input") == 0 || strcmp(argv[i], "-i") == 0) {
            if (i < argc-1)
                *input = argv[++i];
            else {
                error = true;
                break;
            }
        } else if (strcmp(argv[i], "--tamanho") == 0 || strcmp(argv[i], "-t") == 0) {
            if (i < argc-1)
                *size = atoi(argv[++i]);
            else {
                error = true;
                break;
            }
            if (*size <= 0) {
                error = true;
                break;
            }
        } else if (strcmp(argv[i], "--algoritmo") == 0 || strcmp(argv[i], "-a") == 0) {
            if (i < argc-1)
                to_lowercase(argv[++i]);
            else {
                error = true;
                break;
            }
            if (strstr(argv[i], "quick"))
                *mode = 2;
            else if (strstr(argv[i], "merge"))
                *mode = 3;
            else if (strstr(argv[i], "bubble"))
                *mode = 4;
            else if (strstr(argv[i], "selection"))
                *mode = 5;
            else if (strstr(argv[i], "insertion"))
                *mode = 6;
            else
                error = true;
        } else if (strcmp(argv[i], "--benchmark") == 0 || strcmp(argv[i], "-b") == 0) {
            *mode = 1;
        } else if (strcmp(argv[i], "--adaptativo") == 0 || strcmp(argv[i], "-A") == 0) {
            *mode = 0;
        } else
            error = true;
    }
    if (error || help) {
        // Common for both
        printf( "\nUsage: %s [-i <file>] [-t <tamanho>] [-a <alg>] [-b] [-A]\n", argv[0]);
        if (error)
            printf("Try '%s --help' for more information.\n", argv[0]);
        // Help message
        if (help) {
            printf( "Quando sem <file>, ou quando <file> é -, lê da entrada padrão."
                    "Entrada:\n"
                    "    -i, --input <file>           Path <file> do arquivo de entrada\n" 
                    "    -t, --tamanho <tamanho>      Tamanho do array a ser ordenado\n"
                    "Operação:\n"
                    "    -a, --algoritmo <alg>        Fixa um algoritmo de ordenação <alg> dentre as opções:\n"
                    "        quick\n"
                    "        merge\n"
                    "        bubble\n"
                    "        insertion\n"
                    "        selection\n"
                    "    -b, --benchmark              Usa todos os algoritmos de ordenação e compara suas métricas\n"
                    "    -A, --adaptativo             Usa heurísticas para determinar o melhor algoritmo; é a opção padrão\n"
                    );
        }
        exit(0);
    }
}

// Conta as linhas no arquivo
int count_lines (FILE* file) {
    int c;
    int lines = 0;
    do {
        c = fgetc(file);
        if (c == '\n')
            lines++;
    } while (c != EOF);
    rewind(file);
    return lines;
}

// Lê array de um arquivo
int* read_file (char* input, int* size) {
    // Abre arquivo
    FILE* file = fopen(input, "r");
    if (file == NULL) {
        printf("ERROR: Cannot open \"%s\" (No such file or directory)", input);
        exit(0);
    }

    // Se o usuário não forneceu o tamanho, o obtém
    if (*size == 0)
        *size = count_lines(file);

    // Aloca, lê e retorna o array
    int* array = calloc(*size, sizeof(int));
    if (array == NULL) {
        printf("Error allocating array\nIs it too big or just random error?\n");
        exit(0);
    }
    for (int i = 0; i < *size; i++)
        if (fscanf(file, "%d", &array[i]) != 1) {
            printf("Error while reading file\nPlease verify you only have numbers there and that they all fit in an int\n");
            exit(0);
        }
    return array;
}

// Lê array do STDIN
int* read_array (int* size) {
    // Lê tamanho, caso não haja
    if (*size) {
        printf("Tamanho do array: %d\nForneça os elementos aqui:\n", *size);
    } else {
        printf("Forneça o tamanho do array:\n");
        if (scanf("%d", size) != 1 || *size <= 0) {
            printf("ERROR: Invalid array size\n");
            exit(0);
        }
        printf("Agora forneça seus elementos aqui:\n");
    }

    // Aloca, lê e retorna o array
    int* array = calloc(*size, sizeof(int));
    if (array == NULL) {
        printf("Error allocating array\nIs it too big or just random error?\n");
        exit(0);
    }
    for (int i = 0; i < *size; i++)
        if (scanf("%d", &array[i]) != 1) {
            printf("Error while reading file\nPlease verify you only have numbers there and that they all fit in an int\n");
            exit(0);
        }
    return array;
}

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
        printf("#Todo\n");
        exit(0);
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
