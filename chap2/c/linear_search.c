#include <stdio.h>

#define SIZE 6

int linear_search(int* numbers, int value){

    for(int i = 0; i < SIZE; i++){
        if(numbers[i] == value){
            return i;
        }
    }

    return -1;
}

int main(void){

    int numbers[SIZE] = {31,41,59,26,41,58};
    int value1 = 26;
    int value2 = 100;

    printf("\nIndex: %d\n", linear_search(numbers, value1));
    printf("\nIndex: %d\n", linear_search(numbers, value2));

    return 0;
}