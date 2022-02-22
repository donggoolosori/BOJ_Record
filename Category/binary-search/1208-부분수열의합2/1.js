'use strict';
const fs = require('fs');

function solution(input) {
  const [n, s] = input[0].split(' ').map(Number);
  const nums = input[1].split(' ').map(Number);

  nums.sort((a, b) => a - b);

  const sumMap = {};

  let cnt = 0;

  function findPartialSum(cur, end, sum, isLeft) {
    if (cur === end) {
      if (isLeft) {
        if (!sumMap[sum]) sumMap[sum] = 0;
        sumMap[sum]++;
      } else {
        cnt += sumMap[s - sum] ?? 0;
      }

      return;
    }

    findPartialSum(cur + 1, end, sum + nums[cur], isLeft);
    findPartialSum(cur + 1, end, sum, isLeft);
  }

  const mid = parseInt(n / 2);

  findPartialSum(0, mid + 1, 0, true);
  findPartialSum(mid + 1, n, 0, false);

  console.log(s === 0 ? cnt - 1 : cnt);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
