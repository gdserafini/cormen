#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int* bit_sum(int* byte1, int* byte2, int size){
    //aloca p/ retornar
    int* result_bit = malloc(sizeof(int) * size);
    //bit que "sobe" na soma
    int temp_bit = 0;

    /*
        verifica qual soma será feita 0,1,2 ou 3
    */
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
        printf("%d ", byte[i]);
    }
    printf("\n");
}

int main(void){

    int byte1[SIZE] = {0,0,0,1,0,1,0,1};
    int byte2[SIZE] = {0,1,0,0,0,0,1,1};
    int* byte_result = bit_sum(byte1, byte2, SIZE);

    print_byte(byte1, SIZE);
    print_byte(byte2, SIZE);
    print_byte(byte_result, SIZE);

    return 0;
}