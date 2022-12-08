package chap2.java;

public class LinearSearch {

    public static boolean find = false;
    public static final int SIZE = 6;

    public static void main(String[] args){

        int[] numbers = {31,41,59,26,41,58};
        int value1 = 26;
        int value2 = 100;

        System.out.println("Index: " + Linear.search(numbers, value1));
        find = false;
        System.out.println("Index: " + Linear.search(numbers, value2));
        
    }
}

class Linear{

    private static boolean test(){
        return LinearSearch.find;
    }

    static int search(int[] numbers, int value){
        System.out.println(!test());

        for(int i = 0; i < numbers.length; i++){
            if(numbers[i] == value){
                LinearSearch.find = true;
                System.out.println(test());
                return i;
            }
            System.out.println(!test());
        }
        System.out.println(!test());
        return -1;
    }

}
