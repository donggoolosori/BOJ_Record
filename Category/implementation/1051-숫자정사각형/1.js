'use strict';
const fs = require('fs');

function solution(input) {
  const [N, M] = input[0].split(' ').map(Number);

  const grid = input.slice(1);

  let ans = 1;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      const num = grid[i][j];

      for (let k = 1; k + i < N && k + j < M; k++) {
        if (
          grid[i][j + k] != num ||
          grid[i + k][j] != num ||
          grid[i + k][j + k] != num
        )
          continue;
        ans = Math.max(ans, (k + 1) * (k + 1));
      }
    }
  }

  console.log(ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
