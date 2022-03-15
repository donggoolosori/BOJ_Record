'use strict';
const fs = require('fs');

function solution(input) {
  const N = Number(input[0]);

  const len = N.toString().length;

  let ans = 0,
    mul = Math.pow(10, len - 1);

  if (len === 1) {
    console.log(N);
    return;
  }

  ans += (N - mul + 1) * len;

  for (let i = len - 1; i > 0; i--) {
    ans += (mul - mul / 10) * i;
    mul /= 10;
  }

  console.log(ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
