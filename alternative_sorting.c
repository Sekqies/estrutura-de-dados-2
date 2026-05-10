int min(int a, int b){
    return a<b? a : b;
}

int max(int a, int b){
    return a>b? a : b;
}

int abs(int a){
    return a>0? a: -a;
}


// O(n + k), onde k = (max(ar) - min(ar))
void count_sort(int* ar, const int n){
    int smallest = ar[0];
    int largest = ar[0];
    for(int i = 0; i < n; ++i){
        smallest = min(smallest,ar[i]);
        largest = max(largest,ar[i]);
    }
    // normalmente, o count sort tem um problema que você não pode tratar números negativos, já que eles não são indexáveis
    // nesse caso, basta fazermos ao invés de smallest para largest, indexar de 0 até largest-smallest

    // então, ao invés de indexar os valores como bucket[ar[i]], que tem index i e [smallest,largest],
    // se indexa através de bucket[abs(ar[i] - smallest)], que tem index 0 e abs(largest-smallest)
    const int bucket_size = abs(largest-smallest) + 1;
    int* bucket = (int*) calloc(bucket_size, sizeof(int));
    for(int i = 0; i < n; ++i){
        int normalized_index = abs(ar[i] - smallest);
        // bucket é 0-inicializado pelo calloc
        bucket[normalized_index]++;
    }
    int idx = 0;
    for(int i = 0; i < bucket_size; ++i){
        int count = bucket[i];
        while(count--){
            ar[idx++] = i + smallest;
        }
    }
    free(bucket);
}

