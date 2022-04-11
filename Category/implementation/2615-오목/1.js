'use strict';
const fs = require('fs');
const MAX = 19;
const dy = [0, 1, 1, 1],
  dx = [1, 1, 0, -1];
const visit = Array.from({ length: MAX }, () =>
  Array.from({ length: MAX }, () => [0, 0, 0, 0])
);

function solution(board) {
  for (let i = 0; i < MAX; i++) {
    for (let j = 0; j < MAX; j++) {
      if (board[i][j] === 0) continue;

      for (let k = 0; k < 4; k++) {
        if (visit[i][j][k]) continue;

        if (isWin(board, i, j, k)) {
          return;
        }
      }
    }
  }
  console.log(0);
}

function isWin(board, y, x, dir) {
  let ny = y,
    nx = x,
    count = 0;

  while (true) {
    if (ny < 0 || nx < 0 || ny >= MAX || nx >= MAX) break;

    if (board[y][x] !== board[ny][nx]) {
      break;
    }

    visit[ny][nx][dir] = true;

    count++;

    (ny = ny + dy[dir]), (nx = nx + dx[dir]);
  }

  if (count === 5) {
    const cands = [
      [y + dy[dir] * 4, x + dx[dir] * 4],
      [y, x],
    ];
    cands.sort((a, b) => {
      if (a[1] === b[1]) {
        return a[0] - b[0];
      }
      return a[1] - b[1];
    });
    console.log(board[y][x]);
    console.log(cands[0][0] + 1, cands[0][1] + 1);
    return true;
  } else {
    return false;
  }
}

function input() {
  const read = fs.readFileSync('input.txt', 'utf-8').split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  const board = read.map((row) => row.split(' ').map(Number));

  return board;
}

solution(input());
