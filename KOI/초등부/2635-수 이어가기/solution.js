'use strict';
const fs = require('fs');
const path = require('path');

function solution(input) {
  const n = Number(input[0]);

  let res = [];
  for (let i = n; i >= (n / 2) >> 0; i--) {
    let curr = [n, i, n - i];
    while (true) {
      const next = curr[curr.length - 2] - curr[curr.length - 1];
      if (next < 0) break;
      curr.push(next);
    }
    if (curr.length > res.length) {
      res = [...curr];
    }
  }

  return res;
}

function printAnswer(ans) {
  console.log(ans.length);
  console.log(ans.reduce((res, num) => res + ' ' + num));
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, '/input/input-0.txt'), 'utf-8')
    .split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

printAnswer(solution(...input()));
