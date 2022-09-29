'use strict';
const fs = require('fs');
const path = require('path');

function solution(input) {
  const positions = input.map((s) => s.split(' ').map(Number));

  const map = Array.from({ length: 101 }, () =>
    Array.from({ length: 101 }, () => 0)
  );

  positions.forEach(([x1, y1, x2, y2]) => {
    for (let y = y1; y < y2; y++) {
      for (let x = x1; x < x2; x++) {
        map[y][x] = 1;
      }
    }
  });

  return map.reduce((acc, row) => {
    return acc + row.reduce((acc, cur) => acc + cur);
  }, 0);
}

function printAnswer(ans) {
  console.log(ans);
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, '/input/input-0.txt'), 'utf-8')
    .split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

printAnswer(solution(...input()));
