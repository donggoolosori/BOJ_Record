'use strict';
const fs = require('fs');

function solution(input) {
  const positions = input[0].split(' ').map(Number);
  const n = positions.length;

  const power = Array.from({ length: 5 }, () =>
    Array.from({ length: 5 }, () => 0)
  );

  for (let e = 1; e <= 4; e++) {
    power[0][e] = 2;
  }

  for (let s = 1; s <= 4; s++) {
    for (let e = 1; e <= 4; e++) {
      if (s === e) {
        power[s][e] = 1;
      } else if (Math.abs(e - s) === 2) {
        power[s][e] = 4;
      } else {
        power[s][e] = 3;
      }
    }
  }

  const dp = Array.from({ length: n }, () =>
    Array.from({ length: 5 }, () => Array.from({ length: 5 }, () => -1))
  );

  function dfs(idx, l, r) {
    if (idx === n) {
      return 0;
    }

    if (dp[idx][l][r] !== -1) {
      return dp[idx][l][r];
    }

    let ret = 2e9;

    const next = positions[idx];

    if (next !== r) {
      ret = Math.min(ret, dfs(idx + 1, next, r) + power[l][next]);
    }
    if (next !== l) {
      ret = Math.min(ret, dfs(idx + 1, l, next) + power[r][next]);
    }

    return (dp[idx][l][r] = ret);
  }

  console.log(dfs(0, 0, 0));
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
