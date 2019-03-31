'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the plusMinus function below.
function plusMinus(arr) {
    let pos = [];
    let neg = [];
    let zeroes = [];

    arr.forEach(x => {
        if(x > 0) {
        pos.push(x);
    }
        else if (x < 0) {
        neg.push(x)
    }
        else zeroes.push(x);
    });
    
    console.log(pos.length / arr.length)
    console.log(neg.length / arr.length)
    console.log(zeroes.length / arr.length)
}

function main() {
    const n = parseInt(readLine(), 10);

    const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

    plusMinus(arr);
}

