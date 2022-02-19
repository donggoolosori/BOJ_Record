'use strict';
const fs = require('fs');

function solution(input) {
  const [n, nums] = input;
  const arr = nums.split(' ').map(Number);
  const dp = Array.from({ length: n }, () => 0);

  let ans = 0;

  for (let i = 0; i < n; i++) {
    let partialLIS = 0;
    for (let j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        partialLIS = Math.max(partialLIS, dp[j]);
      }
    }
    dp[i] = partialLIS + 1;
    ans = Math.max(ans, dp[i]);
  }

  console.log(ans);
}

// const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
