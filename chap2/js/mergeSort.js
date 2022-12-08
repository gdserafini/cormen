let numbers = [5,77,1,2,100];

function merge(begin, mid, end){
    const size1 = mid - begin + 1;
    const size2 = end - mid; 
    let i, j;
    let left_array = [];
    let right_array = [];

    for (i = 0; i < size1; i++){
        left_array.push(numbers[begin + i]);
    }

    for (j = 0; j < size2; j++){
        right_array.push(numbers[mid + j + 1]);
    }

    i = j = 0;
    left_array.push(Number.MAX_SAFE_INTEGER);
    right_array.push(Number.MAX_SAFE_INTEGER);

    for (let k = begin; k <= end; k++) {
        if (left_array[i] <= right_array[j]) {
            numbers[k] = left_array[i];
            i++;
        } else {
            numbers[k] = right_array[j];
            j++;
        }
    }
}

function mergeSort(begin, end){
    if(begin < end) {
        let mid = (begin + end) / 2;

        mergeSort(begin, mid);
        mergeSort(mid + 1, end);
        merge(begin, mid, end);
    }
}

mergeSort(0, 4);

for(let i = 0; i < 4; i++){
    console.log(numbers[i]);
}