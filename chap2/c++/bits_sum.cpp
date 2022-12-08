#include <iostream>
#include <cstdlib>

#define SIZE 8

using namespace std;

int* bit_sum(int* byte1, int* byte2, int size){
    int* result_bit = (int*)malloc(sizeof(int) * size);
    int temp_bit = 0;

    for(int i = size-1; i >-1; i--){
        if((byte1[i] == 1 && byte2[i] == 1 && temp_bit == 0) ||
        (byte1[i] != byte2[i] && temp_bit == 1)){
            result_bit[i] = 0;
            temp_bit = 1;
        }
        else if(byte1[i] == 1 && byte2[i] == 1 && temp_bit == 1){
            result_bit[i] = 1;
            temp_bit = 1;
        }
        else if((byte1[i] != byte2[i] && temp_bit == 0) ||
        (byte1[i] == 0 && byte2[i] == 0 && temp_bit == 1)) {
            result_bit[i] = 1;
            temp_bit = 0;
        }
        else if(byte1[i] == 0 && byte2[i] == 0 && temp_bit == 0){
            result_bit[i] = 0;
            temp_bit = 0;
        }
    }

    return result_bit;
}

void print_byte(int* byte, int size){
    for(int i = 0; i < size; i++){
        cout << byte[i] << " ";
    }
    cout << endl;
}

int main(void){

    int byte1[SIZE] = {0,0,0,1,0,1,0,1};
    int byte2[SIZE] = {0,1,0,0,0,0,1,1};

    int* result = bit_sum(byte1, byte2, SIZE);

    print_byte(byte1, SIZE);
    print_byte(byte2, SIZE);
    print_byte(result, SIZE);

    return 0;
}