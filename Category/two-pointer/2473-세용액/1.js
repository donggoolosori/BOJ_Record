'use strict';
const fs = require('fs');

function solution(input) {
  const n = Number(input[0]);
  const arr = input[1].split(' ').map(Number);

  arr.sort((a, b) => a - b);

  let minVal = 3000000001;
  let ans = [];

  for (let i = 0; i < n; i++) {
    const num1 = arr[i];

    let low = i + 1,
      high = n - 1;

    while (low < high) {
      const num2 = arr[low],
        num3 = arr[high];

      const sum = num1 + num2 + num3;

      if (minVal > Math.abs(sum)) {
        minVal = Math.abs(sum);
        ans = [num1, num2, num3];
      }

      if (sum === 0) break;
      else if (sum > 0) {
        high--;
      } else {
        low++;
      }
    }
  }

  console.log(...ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
