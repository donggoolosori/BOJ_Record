'use strict';
const fs = require('fs');

function solution(input) {
  let T = Number(input[0]);
  let readRow = 1;

  while (T--) {
    const n = Number(input[readRow]);

    const pos = input
      .slice(readRow + 1, readRow + 1 + n)
      .map((str) => str.split(' ').map(Number));

    const visit = {};
    let ans = 987654321;

    function getSumOfVec() {
      let x = 0,
        y = 0;

      for (let i = 0; i < n; i++) {
        if (visit[i]) {
          x += pos[i][0];
          y += pos[i][1];
        } else {
          x -= pos[i][0];
          y -= pos[i][1];
        }
      }

      return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
    }

    function selectEndPoint(cnt, idx) {
      if (cnt === n / 2) {
        ans = Math.min(ans, getSumOfVec());
        return;
      }

      if (idx === n) return;

      selectEndPoint(cnt, idx + 1);
      visit[idx] = true;
      selectEndPoint(cnt + 1, idx + 1);
      visit[idx] = false;
    }

    selectEndPoint(0, 0);

    console.log(ans);

    readRow += n + 1;
  }
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
