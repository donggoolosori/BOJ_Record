'use strict';
const fs = require('fs');

function solution(input) {
  const [strN, strArr] = input;
  const n = Number(strN),
    arr = strArr.split(' ').map(Number);

  let low = 0,
    high = n - 1;
  let minVal = Math.abs(arr[low] + arr[high]);
  let ans = [arr[low], arr[high]];

  while (low < high) {
    const sum = arr[low] + arr[high];

    if (Math.abs(sum) < minVal) {
      minVal = Math.abs(sum);
      ans = [arr[low], arr[high]];
    }

    if (sum === 0) {
      break;
    } else if (sum > 0) {
      high--;
    } else {
      low++;
    }
  }

  console.log(...ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
//const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
