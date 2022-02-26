'use strict';
const fs = require('fs');

const INF = 987654321;

function solution(input) {
  const n = Number(input[0]);
  const costs = input.slice(1, n + 1).map((str) => str.split(' ').map(Number));
  let dp = Array.from({ length: n }, () => [-1, -1, -1]);

  function dfs(L, color, nColor) {
    if (L === 0) {
      if (color === nColor) return INF;
      return costs[0][color];
    }

    let ret = INF;
    if (L === -1) {
      for (let i = 0; i < 3; i++) {
        dp = Array.from({ length: n }, () => [-1, -1, -1]);
        ret = Math.min(ret, dfs(n - 1, i, i));
      }
      return ret;
    }

    if (dp[L][color] !== -1) return dp[L][color];

    for (let i = 0; i < 3; i++) {
      if (i === color) continue;

      ret = Math.min(ret, dfs(L - 1, i, nColor));
    }

    return (dp[L][color] = ret + costs[L][color]);
  }

  console.log(dfs(-1, 0, 0));
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
