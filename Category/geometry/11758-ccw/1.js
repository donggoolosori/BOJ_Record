'use strict';

const fs = require('fs');

function ccw(pos1, pos2, pos3) {
  const [x1, y1] = pos1,
    [x2, y2] = pos2,
    [x3, y3] = pos3;
  return x1 * y2 + x2 * y3 + x3 * y1 - (x1 * y3 + x2 * y1 + x3 * y2);
}

function solution(input) {
  const pos = input.map((str) => str.split(' ').map(Number));

  const ep = ccw(...pos);

  console.log(ep === 0 ? 0 : ep > 0 ? 1 : -1);
}

// const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
