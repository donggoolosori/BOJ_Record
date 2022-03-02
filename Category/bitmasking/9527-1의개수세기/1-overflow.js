'use strict';
const fs = require('fs');

function solution(input) {
  const [A, B] = input[0].split(' ').map(Number);

  const d = [0];

  for (let i = 1; i < 55; i++) {
    d[i] = d[i - 1] * 2 + (1 << i);
  }

  function getNumOf1(x) {
    let res = x & 1;

    for (let i = 54; i > 0; i--) {
      if (x & (1 << i)) {
        res += d[i - 1] + x - (1 << i) + 1;
      }
    }

    return res;
  }

  const ans = getNumOf1(B) - getNumOf1(A - 1);

  console.log(ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
