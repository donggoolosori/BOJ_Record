"use strict";
const fs = require("fs");
const path = require("path");

function solution(n, m, paper) {
  const dy = [-1, 0, 1, 0],
    dx = [0, 1, 0, -1];

  function dfs(y, x) {
    let ret = 1;
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (paper[ny][nx] === 0) continue;
      paper[ny][nx] = 0;
      ret += dfs(ny, nx);
    }
    return ret;
  }

  let count = 0,
    maxArea = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (paper[i][j] === 0) continue;
      paper[i][j] = 0;
      count++;
      maxArea = Math.max(maxArea, dfs(i, j));
    }
  }

  return [count, maxArea];
}

function refineInput(input) {
  const [n, m] = input[0].split(" ").map(Number);

  const paper = input.slice(1, 1 + n).map((s) => s.split(" ").map(Number));

  return [n, m, paper];
}

function printAnswer(ans) {
  console.log(ans[0]);
  console.log(ans[1]);
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, "/input/input-0.txt"), "utf-8")
    .split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
