'use strict';

const fs = require('fs');
const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0,'utf-8').split('\n');

const MAX = 1000000;

function solution() {
  const n = input[0];

  const cache = Array.from({ length: MAX + 1 }, () => 0),
    after = Array.from({ length: MAX + 1 }, () => 0);

  cache[1] = 0;
  after[1] = -1;

  for (let i = 2; i <= n; i++) {
    cache[i] = cache[i - 1] + 1;
    after[i] = i - 1;

    if (i % 2 === 0 && cache[i] > cache[i / 2] + 1) {
      cache[i] = cache[i / 2] + 1;
      after[i] = i / 2;
    }

    if (i % 3 === 0 && cache[i] > cache[i / 3] + 1) {
      cache[i] = cache[i / 3] + 1;
      after[i] = i / 3;
    }
  }

  console.log(cache[n]);
  let paths = '',
    path = n;
  while (path !== -1) {
    paths += path + ' ';
    path = after[path];
  }
  console.log(paths);
}

solution();
