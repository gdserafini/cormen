#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int is_sorted(int* numbers){
    for(int i = 0; i < SIZE-1; i++){
        if(numbers[i] > numbers[i+1]) return 0;
    }
    return 1;
}

void selection_sort(int* numbers){
    if(is_sorted(numbers)) return;

    int count = 0, smaller;

    for(int i = 0; i < SIZE-1; i++){
        smaller = numbers[i];

        for(int j = i+1; j < SIZE; j++){
            if(numbers[j] < smaller){
                smaller = numbers[j];
                count = j;
            }
        }
        
        numbers[count] = numbers[i];
        numbers[i] = smaller;
    }
}

void print_numbers(int* numbers){
    for(int i = 0; i < SIZE; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void){

    int numbers[5] = {6,22,5,1,9};
    selection_sort(numbers);
    print_numbers(numbers);

    return 0;
}