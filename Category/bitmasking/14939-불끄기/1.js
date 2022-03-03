'use strict';
const fs = require('fs');

const MAX = 10;

function strToBit(str) {
  let bit = 0;

  for (let i = 0; i < MAX; i++) {
    if (str[i] === '#') {
      continue;
    }
    bit |= 1 << i;
  }

  return bit;
}

function solution(input) {
  const lights = input.map(strToBit);

  let ans = 2e9;

  function switchLights(simulation, row, col) {
    // 위
    if (row - 1 >= 0) {
      simulation[row - 1] ^= 1 << col;
    }

    // 왼쪽
    if (col - 1 >= 0) {
      simulation[row] ^= 1 << (col - 1);
    }

    // 자신
    simulation[row] ^= 1 << col;

    // 오른쪽
    if (col + 1 < MAX) {
      simulation[row] ^= 1 << (col + 1);
    }

    // 아래
    if (row + 1 < MAX) {
      simulation[row + 1] ^= 1 << col;
    }
  }

  for (let top = 0; top < 1 << MAX; top++) {
    const simulation = [...lights];

    let count = 0;

    for (let col = 0; col < MAX; col++) {
      if (top & (1 << col)) {
        count++;

        switchLights(simulation, 0, col);
      }
    }

    for (let row = 1; row < MAX; row++) {
      for (let col = 0; col < MAX; col++) {
        if (simulation[row - 1] & (1 << col)) {
          count++;

          switchLights(simulation, row, col);
        }
      }
    }

    if (simulation[MAX - 1] === 0) {
      ans = Math.min(ans, count);
    }
  }

  console.log(ans === 2e9 ? -1 : ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
