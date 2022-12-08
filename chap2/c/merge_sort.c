#include <stdio.h>

#define SIZE 5

void merge(int *array, int begin, int mid, int end) {

    int size1 = mid - begin + 1;
    int size2 = end - mid; 
    int i, j;
    int left_array[size1 + 1];
    int right_array[size2 + 1];

    for (i = 0; i < size1; i++){
        left_array[i] = array[begin + i];
    }

    for (j = 0; j < size2; j++){
        right_array[j] = array[mid + j + 1];
    }

    i = j = 0;
    left_array[size1] = __INT_MAX__;
    right_array[size2] = __INT_MAX__;

    for (int k = begin; k <= end; k++) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
    }
}

 void merge_sort(int *array, int begin, int end) {
     if(begin < end) {
         int mid = (begin + end) / 2;

         merge_sort(array, begin, mid);
         merge_sort(array, mid + 1, end);
         merge(array, begin, mid, end);
     }
 }

int main(void){
    int numbers[SIZE] = {5,77,1,2,100};

    merge_sort(numbers, 0, SIZE-1);

    for(int i = 0; i < SIZE; i++){
        printf("%d ", numbers[i]);
    }

    return 0;
}