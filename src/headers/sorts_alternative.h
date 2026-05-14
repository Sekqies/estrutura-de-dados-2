#include "utils.h"
#include <string.h>

void count_sort (int* array, const int n);

// isso é um hack para aceitar argumentos padrões no C. Por padrão, skippable_bytes é 0.

#define bytewise_radix_sort(array, n, ...) \
    bytewise_radix_sort_impl(array, n, ##__VA_ARGS__, 0)

#define bytewise_radix_sort_impl(array, n, skippable, ...) \
    bytewise_radix_sort_fn(array, n, skippable)

void internal_bytewise_radix_sort (int* array, const int n, const unsigned char skippable_bytes);
