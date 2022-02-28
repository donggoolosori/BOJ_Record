'use strict';
const fs = require('fs');

function solution(input) {
  const n = Number(input[0]);
  const MOD = 1e9;
  const fullBit = (1 << 10) - 1;

  if (n < 10) {
    console.log(0);
    return;
  }

  const dp = Array.from({ length: 101 }, () =>
    Array.from({ length: 10 }, () => Array.from({ length: 1 << 10 }, () => 0))
  );

  function dfs(len, num, bit) {
    if (len === -1) {
      let ret = 0;
      for (let s = 1; s <= 9; s++) {
        ret += dfs(1, s, 1 << s);
      }
      return ret % MOD;
    }

    if (dp[len][num][bit]) {
      return dp[len][num][bit];
    }

    if (len === n) {
      return bit === fullBit ? 1 : 0;
    }

    let ret = 0;

    if (num + 1 <= 9) {
      ret += dfs(len + 1, num + 1, bit | (1 << (num + 1)));
    }

    if (num - 1 >= 0) {
      ret += dfs(len + 1, num - 1, bit | (1 << (num - 1)));
    }

    return (dp[len][num][bit] = ret % MOD);
  }

  console.log(dfs(-1, 0, 0));
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
