'use strict';
const fs = require('fs');
const path = require('fs');

function solution(input) {}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, 'input.txt'), 'utf-8')
    .split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

solution(...input());
