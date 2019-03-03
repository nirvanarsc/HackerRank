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

// Complete the staircase function below.
function staircase(n) {
    let space = new Array(n-1).fill(' ');
    let star = new Array(1).fill('#');
    while (star.length <= n) {
        let line = ''
        space.forEach(x => line += x)
        star.forEach(y => line += y);
        console.log(line)
        space.pop()
        star.push('#')
    }
}

function main() {
    const n = parseInt(readLine(), 10);

    staircase(n);
}

