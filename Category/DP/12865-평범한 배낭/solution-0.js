'use strict';
const fs = require('fs');
const path = require('path');

function solution(input) {
  const [N, K] = input[0].split(' ').map(Number);

  const bag = input.slice(1, -1).map((s) => {
    const [w, v] = s.split(' ').map(Number);
    return { w, v };
  });

  const dp = Array.from({ length: K + 1 }, () => 0);

  let ret = 0;
  for (let i = 0; i < N; i++) {
    for (let j = K; j >= bag[i].w; j--) {
      dp[j] = Math.max(dp[j], dp[j - bag[i].w] + bag[i].v);
      ret = Math.max(ret, dp[j]);
    }
  }
  return ret;
}

function printAns(ans) {
  console.log(ans);
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, '/input/input-0.txt'), 'utf-8')
    .split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

printAns(solution(...input()));
