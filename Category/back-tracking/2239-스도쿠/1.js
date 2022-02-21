'use strict';
const fs = require('fs');

function solution(input) {
  const board = input.map((str) => str.split('').map(Number));

  const MAX = 9;
  const row = Array.from({ length: MAX }, () => ({}));
  const col = Array.from({ length: MAX }, () => ({}));
  const square = Array.from({ length: MAX }, () => ({}));

  for (let i = 0; i < MAX; i++) {
    for (let j = 0; j < MAX; j++) {
      if (board[i][j] === 0) continue;

      row[i][board[i][j]] = true;
      col[j][board[i][j]] = true;
      square[parseInt(i / 3) * 3 + parseInt(j / 3)][board[i][j]] = true;
    }
  }

  let flag = false;

  function dfs(cnt) {
    if (flag) return;

    if (cnt === 81) {
      board.forEach((r) => console.log(r.join('')));
      flag = true;
      return;
    }

    const y = parseInt(cnt / MAX);
    const x = cnt % MAX;
    const squareNum = parseInt(y / 3) * 3 + parseInt(x / 3);

    if (board[y][x] !== 0) {
      dfs(cnt + 1);
      return;
    }

    for (let i = 1; i <= 9; i++) {
      if (!row[y][i] && !col[x][i] && !square[squareNum][i]) {
        row[y][i] = true;
        col[x][i] = true;
        square[squareNum][i] = true;
        board[y][x] = i;
        dfs(cnt + 1);
        board[y][x] = 0;
        row[y][i] = false;
        col[x][i] = false;
        square[squareNum][i] = false;
      }
    }
  }

  dfs(0);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
