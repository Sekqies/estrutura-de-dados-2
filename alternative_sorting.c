
int fast_log2(unsigned int v){
    int l = 0;
    int r = 32;
    while(l < r){
        const int m = (l+r)/2;
        if(v & (1<<m)){
            l = m + 1;
        }
        else 
            r = m;
    }
}

int count_bytes(unsigned int v){
    return (fast_log2(v) >> 3) + 1;
}


// returns the nth byte of an unsigned integer, starting from the lsB
// shifting to the right by 8n will remove the lower 8n (or lower n bytes). 
// taking the AND with 0xFF will give the value of the first byte.
unsigned char get_nth_byte(unsigned int v, unsigned char n){
    return (v >> (n<<3)) & 0xFF;
}

int min(int a, int b){
    return a<b? a : b;
}

int max(int a, int b){
    return a>b? a : b;
}

int abs(int a){
    return a>0? a: -a;
}


// execução: O(n + k), onde k = (max(ar) - min(ar))
// memória auxiliar: O(k)
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

int radix_bucket[256];


// fazemos radix sort byte a byte já que isso permite que trabalhemos somente com log2 e operações bitwise
// que são, na prática, O(1)

// execução: O(n)
// memória auxiliar: O(n)
void bytewise_radix_sort(int* ar, const int n){
    int* tmp = calloc(n,sizeof(int));

    // radix sort tem o problema que ele não sabe discernir números negativos de positivos.
    // se tratarmos o bit de sinal como um bit de valor (ex: -3 = (1) 11 = 111 = 5), teremos problema de ordenação, já que todo
    // número negativo terá o primeiro bit setado, fazendo que ele seja maior que os positivos.
    // para isso, invertemos o primeiro bit de cada número. dessa forma, 
    // um número positivo sempre será maior que um número negativo, e a comparação de magnitude ocorre normalmente.   
    for(int i = 0; i < n; ++i){
        ar[i] ^= 0x80000000;
    }

    for(unsigned char byte_idx = 0; byte_idx < 4; ++byte_idx){
        memset(radix_bucket,0,256 * sizeof(int)); 
        for(int i = 0; i < n; ++i){
            unsigned char current_byte = get_nth_byte(ar[i],byte_idx);
            radix_bucket[current_byte]++;
        }
        for(int i = 1; i < 256; ++i){
            radix_bucket[i] += radix_bucket[i-1];
        }
        for(int i = n-1; i >=0; --i){
            unsigned char current_byte = get_nth_byte(ar[i],byte_idx);
            tmp[--radix_bucket[current_byte]] = ar[i];
        }
        memcpy(ar, tmp, n * sizeof(int));
    }
    for(int i =0; i < n; ++i){
        ar[i] ^= 0x80000000;
    }
    free(tmp);
}