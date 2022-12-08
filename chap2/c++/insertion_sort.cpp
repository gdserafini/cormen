#include <iostream>

#define SIZE 6

using namespace std;

bool test_algorithm(int* numbers, int length){
    for(int i = 0; i < length-1; i++){
        if(numbers[i] > numbers[i+1]) return false;
    }
    return true;
}   

void print_numbers(int* numbers){
    for(int i = 0; i < SIZE; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
}

bool reverse_test(int* numbers, int size){
    for(int i = SIZE-1; i > size; i--){
        if(numbers[i] < numbers[i+1]) return false;
    }
    return true;
}

void reverse_insertion_sort(int* numbers){
    cout << !reverse_test(numbers, -1) << endl;

    for(int i = SIZE-2; i > -1; i--){
        int key = numbers[i];
        int j = i + 1;

        while(j < SIZE && numbers[j] > key){
            numbers[j-1] = numbers[j];
            j++;
        }

        numbers[j-1] = key;
        cout << reverse_test(numbers, j-1) << endl;
    }

    cout << reverse_test(numbers, 0) << endl;
}

void insertion_sort(int* numbers){
    cout << !test_algorithm(numbers, SIZE) << endl;

    for(int i = 1; i < SIZE; i++){
        int key = numbers[i];
        int j = i - 1;

        while(j > -1 && numbers[j] > key){
            numbers[j+1] = numbers[j];
            j--;
        }

        numbers[j+1] = key;

        cout << test_algorithm(numbers, j+1) << endl;
    }
    cout << test_algorithm(numbers, SIZE) << endl;
}

int main(void){

    int numbers[SIZE] = {5,2,4,6,1,3};

    print_numbers(numbers);
    insertion_sort(numbers);
    print_numbers(numbers);

    print_numbers(numbers);
    reverse_insertion_sort(numbers);
    print_numbers(numbers);

    return 0;
}