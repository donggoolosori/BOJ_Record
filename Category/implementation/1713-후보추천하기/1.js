'use strict';
const fs = require('fs');

function solution(n, m, recommends) {
  const candidates = [];

  for (let i = 0; i < m; i++) {
    const num = recommends[i];

    const idx = candidates.findIndex((obj) => obj.num === num);

    if (idx !== -1) {
      candidates[idx].count++;
    } else {
      if (candidates.length === n) {
        candidates
          .sort((a, b) => {
            if (a.count === b.count) {
              return b.time - a.time;
            }
            return b.count - a.count;
          })
          .pop();
      }

      candidates.push({ num, count: 1, time: i });
    }
  }

  const ans = candidates
    .sort((a, b) => a.num - b.num)
    .reduce((res, obj) => res + obj.num + ' ', '');

  console.log(ans);
}

function input() {
  const read = fs.readFileSync('input.txt', 'utf-8').split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  const n = Number(read[0]),
    m = Number(read[1]);
  const recommends = read[2].split(' ').map(Number);

  return [n, m, recommends];
}

solution(...input());
