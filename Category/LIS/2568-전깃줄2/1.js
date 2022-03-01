'use strict';
const fs = require('fs');

function lowerBound(arr, target) {
  let low = 0,
    high = arr.length - 1;

  while (low < high) {
    const mid = parseInt((low + high) / 2);

    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

function solution(input) {
  const n = Number(input[0]);

  const lines = input.slice(1, 1 + n).map((str) => str.split(' ').map(Number));

  lines.sort((a, b) => a[0] - b[0]);

  const stack = [];
  const p = [];

  lines.forEach(([_, num]) => {
    if (stack.length === 0 || stack[stack.length - 1] < num) {
      stack.push(num);

      p.push(stack.length - 1);
    } else {
      const lb = lowerBound(stack, num);

      stack[lb] = num;

      p.push(lb);
    }
  });

  const delLines = [];
  let idx = stack.length - 1;
  for (let i = p.length - 1; i >= 0; i--) {
    if (p[i] === idx) {
      idx--;
      continue;
    }

    delLines.push(lines[i][0]);
  }

  delLines.sort((a, b) => a - b);

  const ans = delLines.reduce((prev, curr) => {
    return prev + '\n' + curr;
  }, delLines.length);

  console.log(ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
