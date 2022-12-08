package chap2.java;

public class MergeSort{

    public static void main(String[] args){

        int[] numbers = {5,77,1,2,100};

        var marge = new Marge();
        marge.sort(numbers, 0, numbers.length-1);

        for(int i = 0; i < numbers.length; i++){
            System.out.print(numbers[i] + " ");
        }

    }

}

class Marge{

    public void sort(int[] array, int begin, int end){
        if(begin < end) {
            int mid = (begin + end) / 2;
   
            sort(array, begin, mid);
            sort(array, mid + 1, end);
            merge(array, begin, mid, end);
        }
    }

    private void merge(int[] array, int begin, int mid, int end){
        int size1 = mid - begin + 1;
        int size2 = end - mid; 
        int i, j;
        int[] left_array = new int[size1 + 1];
        int[] right_array = new int[size2 + 1];

        for (i = 0; i < size1; i++){
            left_array[i] = array[begin + i];
        }

        for (j = 0; j < size2; j++){
            right_array[j] = array[mid + j + 1];
        }

        i = j = 0;
        left_array[size1] = Integer.MAX_VALUE;
        right_array[size2] = Integer.MAX_VALUE;

        for (int k = begin; k <= end; k++) {
            if (left_array[i] <= right_array[j]) {
                array[k] = left_array[i];
                i++;
            } else {
                array[k] = right_array[j];
                j++;
            }
        }
    }

}