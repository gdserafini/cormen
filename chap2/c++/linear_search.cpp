#include <iostream>

#define SIZE 6
bool find = false;

bool test(){
    return find;
}

int linear_search(int* numbers, int value){
    std::cout << !test() << std::endl;

    for(int i = 0; i < SIZE; i++){
        if(numbers[i] == value){
            find = true;
            std::cout << test() << std::endl;
            return i;
        }
        std::cout << !test() << std::endl;
    }
    std::cout << !test() << std::endl;
    return -1;
}

int main(void){

    int numbers[SIZE] = {31,41,59,26,41,58};
    int value1 = 26;
    int value2 = 100;

    std::cout << "Index: " << linear_search(numbers, value1) << std::endl;
    find = false;
    std::cout << "Index: " << linear_search(numbers, value2) << std::endl;

    return 0;
}