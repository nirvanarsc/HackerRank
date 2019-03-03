'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(str => str.trim());

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the timeConversion function below.
 */
function timeConversion(s) {
    if (s === '12:00:00AM') return '00:00:00'
    if (s === '12:00:00PM') return '12:00:00'
    let zone = s.slice(s.length - 2, s.length);
    let hour = s.slice(0, 2);
    if (zone === 'PM' && parseInt(hour, 10) !== 12) {
        let hourNr = parseInt(hour, 10);
        hour = (12 + hourNr).toString();
    }
    if (zone === 'AM' && parseInt(hour, 10) === 12) {
        hour = '00';
    }

    return hour + s.slice(2, s.length - 2);
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const s = readLine();

    let result = timeConversion(s);

    ws.write(result + "\n");

    ws.end();
}

