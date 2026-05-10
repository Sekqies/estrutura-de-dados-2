void swap(int* a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void bubble_sort(int* ar, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < n; ++j){
            if(ar[j] < ar[j-1]){
                swap(&ar[j], &ar[j-1]);
            } 
        }
    }
}

void selection_sort(int* ar, int n){
    for(int i = 0; i < n; ++i){
        int smallest_index = i;
        for(int j = 0; j < n; ++j){
            if(ar[i] > ar[j]) smallest_index = j;
        }
        swap(ar[i],ar[j]);
    }
}

void insert_sort(int* ar, int n){
    for(int i = 1; i < n; ++i){
        int j = i-1;
        int key = ar[i];
        while(j >= 0 && ar[j] > key){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
    }
}