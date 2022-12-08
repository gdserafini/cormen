package chap2.java;

public class SelectionSort {

    public static void printNumbers(int[] numbers){
        for(int n : numbers){ System.out.print(n + " "); }
    }

    public static void main(String[] args){

        int[] numbers = {6,22,5,1,9,44};
        Selection.sort(numbers);
        printNumbers(numbers);
 
    }
    
}

class Selection{

    public static void sort(int[] numbers){

        int smaller, count = 0;

        for(int i = 0; i < numbers.length-1; i++){
            smaller = numbers[i];

            for(int j = i+1; j < numbers.length; j++){
                if(numbers[j] < smaller){
                    smaller = numbers[j];
                    count = j;
                }
            }

            numbers[count] = numbers[i];
            numbers[i] = smaller;
        }

    }

}
