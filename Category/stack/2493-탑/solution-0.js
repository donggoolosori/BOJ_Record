'use strict';
const fs = require('fs');
const path = require('path');

function solution(input) {
  const n = +input[0];
  const heights = input[1].split(' ').map(Number);

  const res = [0],
    stack = [{ val: heights[0], index: 0 }];
  for (let i = 1; i < n; i++) {
    if (stack.length === 0) {
      stack.push({ val: heights[i], index: i });
      res.push(0);
    } else if (stack[stack.length - 1].val >= heights[i]) {
      res.push(stack[stack.length - 1].index + 1);
      stack.push({ val: heights[i], index: i });
    } else {
      while (stack.length && stack[stack.length - 1].val < heights[i]) {
        stack.pop();
      }
      if (stack.length === 0) {
        res.push(0);
      } else {
        res.push(stack[stack.length - 1].index + 1);
      }
      stack.push({ val: heights[i], index: i });
    }
  }
  console.log(res.reduce((ret, num) => ret + ' ' + num));
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, '/input/input-0.txt'), 'utf-8')
    .split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

solution(...input());
