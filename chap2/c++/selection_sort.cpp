#include <iostream>

#define SIZE 6

using namespace std;

bool is_sorted(int* numbers){
    for(int i = 0; i < SIZE-1; i++){
        if(numbers[i] > numbers[i+1]) return false;
    }
    return true;
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
        cout << numbers[i] << " ";
    }
    cout << endl;

}

int main(void){

    int numbers[SIZE] = {6,22,5,1,9,48};
    selection_sort(numbers);
    print_numbers(numbers);

    return 0;
}