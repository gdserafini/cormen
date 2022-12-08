package chap2.java;

public class BitsSum{

    public static void printByte(int[] byte1){
        for(int i = 0; i < byte1.length;i ++){
            System.out.print(byte1[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){

        int byte1[] = {0,0,0,1,0,1,0,1};
        int byte2[] = {0,1,0,0,0,0,1,1};

        var sum = Bits.sum(byte1, byte2);

        printByte(byte1);
        printByte(byte2);
        printByte(sum);
        
    }
}

class Bits{

    private static int result_bit[] = {0,0,0,0,0,0,0,0};
    private static int temp_bit;

    public static int[] sum(int[] byte1, int[] byte2){

        for(int i = byte1.length-1; i >-1; i--){
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
}