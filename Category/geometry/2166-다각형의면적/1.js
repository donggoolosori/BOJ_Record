'use strict';

const fs = require('fs');
const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

const n = input[0];
const pos = input.slice(1).map((str) => str.split(' ').map((v) => Number(v)));

function ccw(pos1, pos2, pos3) {
  const [x1, y1] = pos1,
    [x2, y2] = pos2,
    [x3, y3] = pos3;
  return (x1 * y2 + x2 * y3 + x3 * y1 - (x1 * y3 + x2 * y1 + x3 * y2)) / 2;
}

function solution() {
  let ans = 0;

  for (let i = 1; i < n; i++) {
    ans += ccw(pos[0], pos[i - 1], pos[i]);
  }

  ans = Math.abs(ans);

  console.log(ans.toFixed(1));
}

solution();
