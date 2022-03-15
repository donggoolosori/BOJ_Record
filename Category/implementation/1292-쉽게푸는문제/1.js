'use strict';
const fs = require('fs');

function solution(input) {
  const [s, e] = input[0].split(' ').map(Number);

  const sum = Array.from({ length: e + 1 }, () => 0);

  let idx = 1;

  for (let num = 1; num <= e; num++) {
    for (let i = idx; i < i + num && i <= e; i++) {
      sum[i] = sum[i - 1] + num;
    }
    idx += num;
  }

  console.log(sum[e] - sum[s - 1]);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
