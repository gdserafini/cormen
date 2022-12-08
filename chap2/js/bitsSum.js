
const byte1 = [0,0,0,1,0,1,0,1];
const byte2 = [0,1,0,0,0,0,1,1];

function sumBits(byte1, byte2){
    let resultBit = [0,0,0,0,0,0,0,0];
    let tempBit = 0;

    for(let i = byte1.length-1; i >-1; i--){
        if((byte1[i] == 1 && byte2[i] == 1 && tempBit == 0) ||
        (byte1[i] != byte2[i] && tempBit == 1)){
            resultBit[i] = 0;
            tempBit = 1;
        }
        else if(byte1[i] == 1 && byte2[i] == 1 && tempBit == 1){
            resultBit[i] = 1;
            tempBit = 1;
        }
        else if((byte1[i] != byte2[i] && tempBit == 0) ||
        (byte1[i] == 0 && byte2[i] == 0 && tempBit == 1)) {
            resultBit[i] = 1;
            tempBit = 0;
        }
        else if(byte1[i] == 0 && byte2[i] == 0 && tempBit == 0){
            resultBit[i] = 0;
            tempBit = 0;
        }
    }

    return resultBit;
}

function printByte(byte){
    byte.forEach(b => console.log(b));
    console.log();
}

printByte(byte1);
printByte(byte2);
printByte(sumBits(byte1, byte2));
