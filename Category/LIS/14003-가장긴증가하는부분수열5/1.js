'use strict';
const fs = require('fs');

function lowerBound(arr, target) {
  let low = 0,
    high = arr.length - 1;

  while (low < high) {
    const mid = Math.floor((low + high) / 2);

    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

function solution(input) {
  const [n, numStr] = input;

  const nums = numStr.split(' ').map(Number);

  const stack = [nums[0]];
  const pos = [0];

  for (let i = 1; i < n; i++) {
    if (stack[stack.length - 1] < nums[i]) {
      stack.push(nums[i]);
      pos.push(stack.length - 1);
    } else {
      const lb = lowerBound(stack, nums[i]);
      stack[lb] = nums[i];
      pos.push(lb);
    }
  }

  console.log(stack.length);
  let idx = stack.length - 1;
  const lis = Array.from({ length: idx + 1 });
  for (let i = pos.length - 1; i >= 0 && idx >= 0; i--) {
    if (pos[i] === idx) {
      lis[idx--] = nums[i];
    }
  }

  console.log(...lis);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
