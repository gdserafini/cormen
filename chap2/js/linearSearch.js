const numbers = [31,41,59,26,41,58];
const value1 = 26;
const value2 = 100;
let find = false;

function linearSearch(numbers, value){
    console.log(!test());

    for(const i in numbers){
        if(numbers[i] === value){
            find = true;
            console.log(test());
            return i;
        }
        console.log(!test());
    }
    console.log(!test());
    return -1;
}

function test(){ return find; }

console.log("Index: " + linearSearch(numbers, value1));
find = false;
console.log("Index: " + linearSearch(numbers, value2));