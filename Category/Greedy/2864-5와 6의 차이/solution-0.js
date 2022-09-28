'use strict';
const fs = require('fs');
const path = require('path');

function solution(input) {
  const [A, B] = input[0].split(' ');

  const regex5 = /5/g,
    regex6 = /6/g;

  const maxA = A.replace(regex5, '6'),
    maxB = B.replace(regex5, '6');
  const minA = A.replace(regex6, '5'),
    minB = B.replace(regex6, '5');

  return [Number(minA) + Number(minB), Number(maxA) + Number(maxB)];
}

function printAnswer(ans) {
  console.log(ans[0], ans[1]);
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, '/input/input-0.txt'), 'utf-8')
    .split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

printAnswer(solution(...input()));
