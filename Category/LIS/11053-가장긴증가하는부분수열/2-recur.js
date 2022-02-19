'use strict';
const fs = require('fs');

function solution(input) {
  const [n, nums] = input;
  const arr = nums.split(' ').map(Number);
  const dp = Array.from({ length: n }, () => -1);

  function recur(idx) {
    let ret = 0;

    if (idx === -1) {
      for (let i = 0; i < n; i++) {
        ret = Math.max(ret, recur(i));
      }

      return ret;
    }

    if (dp[idx] !== -1) return dp[idx];

    for (let i = 0; i < idx; i++) {
      if (arr[idx] > arr[i]) {
        ret = Math.max(ret, recur(i));
      }
    }

    return (dp[idx] = ret + 1);
  }

  console.log(recur(-1));
}

// const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
