#include "nlogn_complexity.h"

/*---------- Quick Sort ----------*/

void quick_sort (int* array, int begin, int end) {
	if (begin < end) {
		int p = partition(array, begin, end);
		quick_sort(array, begin, p-1);
		quick_sort(array, p+1, end);
	}
}

int partition (int* array, int begin, int end) {
	int pivot = array[begin]; // Make it not fixed
	int left = begin+1;
	int right = end;
	do {
		while (left < end && array[left] < pivot) {
			// ++count;
			left++;
		}
		while (begin < right && pivot <= array[right]) {
			// ++count;
			right--;
		}
		if (left < right) {
            swap(&array[left], &array[right]);
		}
	} while (left < right);
	array[begin] = array[right];
	array[right] = pivot;
	return right;
}

/*---------- Merge Sort ----------*/

void merge_sort (int* array, int begin, int end) {
	if (begin < end) {
		int middle = (begin+end)/2;
		merge_sort(array, begin, middle);
		merge_sort(array, middle+1, end);
		merge(array, begin, end);
	}
}

void merge (int* array, int begin, int end) {
	static int temp_array[10000000]; 
	int middle = (begin+end)/2;
	int i = begin;
	int j = begin;
	int k = middle+1;

	while (j <= middle && k <= end) {
		if (array[j] <= array[k]) {
			temp_array[i] = array[j];
			j++;
		} else {
			temp_array[i] = array[k];
			k++;
		}
		// ++count;
		i++;
	}
	while (j <= middle) {
		temp_array[i] = array[j];
		i++;
		j++;
	}
	while (k <= end) {
		temp_array[i] = array[k];
		i++;
		k++;
	}
	for (i = begin; i <= end; i++)
		array[i] = temp_array[i];
}
