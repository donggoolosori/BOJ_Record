'use strict';
const fs = require('fs');

function solution(input) {
  const INF = 2e9;
  const str = input[0];
  const n = str.length;

  const isPalindrome = Array.from({ length: n }, (_, i) =>
    Array.from({ length: n }, (_, j) => (i === j ? true : false))
  );

  for (let i = 0; i < n - 1; i++) {
    if (str[i] === str[i + 1]) isPalindrome[i][i + 1] = true;
  }

  for (let len = 3; len <= n; len++) {
    for (let s = 0; s < n; s++) {
      const e = s + len - 1;

      if (str[s] === str[e] && isPalindrome[s + 1][e - 1]) {
        isPalindrome[s][e] = true;
      }
    }
  }

  const dp = Array.from({ length: n }, () => INF);

  for (let e = 0; e < n; e++) {
    for (let s = 0; s <= e; s++) {
      if (isPalindrome[s][e]) {
        const prevMinVal = s === 0 ? 0 : dp[s - 1];
        dp[e] = Math.min(dp[e], prevMinVal + 1);
      }
    }
  }

  console.log(dp[n - 1]);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
