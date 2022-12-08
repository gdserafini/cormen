let numbers = [6,22,5,1,9,44];

function selectionSort(numbers){

    let smaller, count = 0;

    for(let i = 0; i < numbers.length-1; i++){
        smaller = numbers[i];

        for(let j = i+1; j < numbers.length; j++){
            if(numbers[j] < smaller){
                smaller = numbers[j];
                count = j;
            }
        }

        numbers[count] = numbers[i];
        numbers[i] = smaller;
    }

}

selectionSort(numbers);
console.log(numbers);