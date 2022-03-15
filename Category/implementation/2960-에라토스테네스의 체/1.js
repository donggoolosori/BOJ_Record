'use strict';
const fs = require('fs');

function solution(input) {
  const [N, K] = input[0].split(' ').map(Number);

  let eraseIdx = 0;
  const erased = {};

  for (let i = 2; i <= N; i++) {
    if (erased[i]) continue;

    for (let j = i; j <= N; j += i) {
      if (erased[j]) continue;
      eraseIdx++;
      erased[j] = true;

      if (eraseIdx === K) {
        console.log(j);
        return;
      }
    }
  }
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
