#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

/*
    testa inicialização -> desordenado
    manutenção -> em cada iteração do laço
        [0-j] -> ordenado, [i-n] -> desordenado
    término -> [0-n] -> ordenado
*/
int test(int* numbers, int size){
    for(int i = 0; i < size; i++){
        if(numbers[i] > numbers[i+1]){ return 0;  }
    }
    return 1;
}

int test_reverse(int* numbers, int size){
    for(int i = SIZE-1; i > size; i--){
        if(numbers[i] > numbers[i+1]) return 0;
    }
    return 1;
}

int* insertion_sort(int* numbers, int size){

    int* numbers_sorted = malloc(sizeof(int) * size);

    //testa inicialização
    printf("\n%d\n", !test(numbers, size));

    for(int i = 1; i < size; i++){
        int key = numbers[i];
        int j = i - 1;

        while(j > -1 && numbers[j] > key){
            numbers_sorted[j+1] = numbers[j];
            j--;
        }

        numbers_sorted[j+1] = key;

        //testa iterações do laço
        printf("\n%d\n", test(numbers_sorted, j+1));
    }

    //testa término
    if(test(numbers_sorted, size)) return numbers_sorted;
    
}

void reverse_insertion_sort(int* numbers){
    printf("\n%d\n", !test_reverse(numbers, -1));

    for(int i = SIZE-2; i > -1; i--){
        int key = numbers[i];
        int j = i + 1;

        while(j < SIZE && numbers[j] > key){
            numbers[j-1] = numbers[j];
            j++;
        }

        numbers[j-1] = key;
        printf("\n%d\n", test_reverse(numbers, j-1));
    }

    printf("\n%d\n", test_reverse(numbers, 0));
}

void print_numbers(int* numbers, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void){

    int numbers[SIZE] = {5,2,4,6,1,3};
    int *sorted_numbers = insertion_sort(numbers, SIZE);

    print_numbers(numbers, SIZE);
    print_numbers(sorted_numbers, SIZE);

    return 0;
}