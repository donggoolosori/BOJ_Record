'use strict';
const fs = require('fs');

function ccw(x1, y1, x2, y2, x3, y3) {
  return x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
}

function solution(input) {
  const [x1, y1, x2, y2] = input[0].split(' ').map(Number);
  const [x3, y3, x4, y4] = input[1].split(' ').map(Number);

  function isCross() {
    const cond1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
    const cond2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);

    function compare(a, b) {
      if (a[0] === b[0]) {
        return a[1] - b[1];
      }
      return a[0] - b[0];
    }

    if (cond1 === 0 && cond2 === 0) {
      const [A, B] = [
        [x1, y1],
        [x2, y2],
      ].sort(compare);
      const [C, D] = [
        [x3, y3],
        [x4, y4],
      ].sort(compare);

      if (compare(A, D) <= 0 && compare(C, B) <= 0) {
        return 1;
      }

      return 0;
    }

    return cond1 <= 0 && cond2 <= 0;
  }

  console.log(isCross() ? 1 : 0);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
