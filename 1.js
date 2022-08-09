'use strict';
const fs = require('fs');

function input() {
  const read = fs.readFileSync('input.txt', 'utf-8').split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

solution(...input());

function solution(input) {
  const counts = Array.from({ length: 26 }, () => 0);

  input[0]
    .split('')
    .forEach((w) => counts[w.charCodeAt(0) - 'a'.charCodeAt(0)]++);

  console.log(...counts);
}
