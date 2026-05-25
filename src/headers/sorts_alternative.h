#include "utils.h"
#include <string.h>

void count_sort (int* array, const int n);

// isso é um hack para aceitar argumentos padrões no C. Por padrão, skippable_bytes é 0.

void bytewise_radix_sort(int* array, const int n);

void internal_bytewise_radix_sort (int* array, const int n, const unsigned char skippable_bytes);
