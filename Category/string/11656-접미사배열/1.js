'use strict';
const fs = require('fs');

function solution(input) {
  const s = input[0];

  const arr = [];

  for (let i = 0; i < s.length; i++) {
    arr.push(s.substr(i));
  }

  arr.sort();

  console.log(
    arr.reduce((prev, curr) => {
      return prev + curr + '\n';
    }, '')
  );
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
