
const SIZE = 6;

function printNumbers(numbers){
    numbers.forEach(n => console.log(n + " "));
}

function testNumbers(numbers, size){
    for(let i = 0; i < size; i++){
        if(numbers[i] > numbers[i+1]) return false;
    }
    return true;
}

function insertionSort(numbers){
    console.log(!testNumbers(numbers, SIZE));

    for(let i = 1; i < numbers.length; i++){
        let key = numbers[i];
        let j = i - 1;

        while(j > -1 && numbers[j] > key){
            numbers[j+1] = numbers[j];
            j--;
        }

        numbers[j+1] = key;
        console.log(testNumbers(numbers, j+1));
    }

    console.log(testNumbers(numbers, SIZE));
}

function reverseTest(numbers, size){
    for(let i = numbers.length-1; i > size; i--){
        if(numbers[i] < numbers[i+1]) return false;
    }
    return true;
}

function reverseInsertionSort(numbers){
    console.log(!reverseTest(numbers, -1));

    for(let i = numbers.length-2; i > -1; i--){
        const key = numbers[i];
        let j = i + 1;

        while(j < numbers.length && numbers[j] > key){
            numbers[j-1] = numbers[j];
            j++;
        }

        numbers[j-1] = key;
        console.log(reverseTest(numbers, j-1));
    }

    console.log(reverseTest(numbers, -1));
}

let numbers = [5,2,4,6,1,3];

printNumbers(numbers);
insertionSort(numbers);
printNumbers(numbers);

printNumbers(numbers);
reverseInsertionSort(numbers);
printNumbers(numbers);
