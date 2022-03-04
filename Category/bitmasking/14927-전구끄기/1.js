'use strict';
const fs = require('fs');

function arrToBit(arr) {
  const N = arr.length;
  let bit = 0;

  for (let i = 0; i < N; i++) {
    if (arr[i] === 0) {
      continue;
    }
    bit |= 1 << i;
  }

  return bit;
}

function solution(input) {
  const N = Number(input[0]);
  const lights = input
    .slice(1, 1 + N)
    .map((str) => str.split(' ').map(Number))
    .map(arrToBit);

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
    if (col + 1 < N) {
      simulation[row] ^= 1 << (col + 1);
    }

    // 아래
    if (row + 1 < N) {
      simulation[row + 1] ^= 1 << col;
    }
  }

  for (let top = 0; top < 1 << N; top++) {
    const simulation = [...lights];

    let count = 0;

    for (let col = 0; col < N; col++) {
      if (top & (1 << col)) {
        count++;

        switchLights(simulation, 0, col);
      }
    }

    for (let row = 1; row < N; row++) {
      for (let col = 0; col < N; col++) {
        if (simulation[row - 1] & (1 << col)) {
          count++;

          switchLights(simulation, row, col);
        }
      }
    }

    if (simulation[N - 1] === 0) {
      ans = Math.min(ans, count);
    }
  }

  console.log(ans === 2e9 ? -1 : ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
