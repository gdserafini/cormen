package chap2.java;

public class InsertionSort{

    static void printNumbers(int[] numbers) {
		
		for(int i = 0; i < numbers.length; i++) {
			System.out.print(numbers[i] + " ");
		}
		System.out.println();
	}

    public static void main(String[] args){
        
        int[] numbers = {5,2,4,6,1,3};
		printNumbers(numbers);
	    Insertion.sort(numbers);
		printNumbers(numbers);

        printNumbers(numbers);
        Insertion.reverseSort(numbers);
        printNumbers(numbers);
    }
}

class Insertion{

    static final int SIZE = 6;

    static void sort(int[] numbers){
        System.out.println(!testAlgorithm(numbers, SIZE));

        for(int i = 1; i < numbers.length; i++){

            int key = numbers[i];
            int j = i - 1;

            while(j > -1 && numbers[j] > key){
                numbers[j+1] = numbers[j];
                j--;
            }

            numbers[j+1] = key;
            System.out.println(testAlgorithm(numbers, j+1));
        }

        System.out.println(testAlgorithm(numbers, SIZE));
    }

    static boolean testAlgorithm(int[] numbers, int size){
        for(int i = 0; i < size-1; i++){
            if(numbers[i] > numbers[i+1]) return false;
        }
        return true;
    }

    static boolean testAlgorithmReverse(int[] numbers, int size){
        for(int i = numbers.length-1; i > size; i--){
            if(numbers[i] < numbers[i+1]) return false;
        }
        return true;
    }

    static void reverseSort(int[] numbers){
        System.out.println(!testAlgorithmReverse(numbers, -1));

        for(int i = numbers.length-2; i > -1; i--){
            int key = numbers[i];
            int j = i + 1;

            while(j < numbers.length && numbers[j] > key){
                numbers[j-1] = numbers[j];
                j++;
            }

            numbers[j-1] = key;
            System.out.println(testAlgorithmReverse(numbers, j-1));
        }

        System.out.println(testAlgorithmReverse(numbers, 0));
    }
    
}