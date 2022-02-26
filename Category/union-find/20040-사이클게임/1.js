'use strict';
const fs = require('fs');

function solution(input) {
  const [n, m] = input[0].split(' ').map(Number);
  const connections = input
    .slice(1, n + 1)
    .map((str) => str.split(' ').map(Number));
  const parent = Array.from({ length: n }, (_, idx) => idx);

  for (let i = 0, turn = 1; i < m; i++, turn++) {
    const [a, b] = connections[i];

    // cycle 발생
    if (!unionParent(a, b)) {
      console.log(turn);
      return;
    }
  }

  console.log(0);

  function getParent(x) {
    if (x === parent[x]) return x;
    return (parent[x] = getParent(parent[x]));
  }

  function unionParent(a, b) {
    a = getParent(a);
    b = getParent(b);

    if (a === b) return false;

    if (a > b) {
      const temp = a;
      a = b;
      b = temp;
    }

    parent[b] = a;

    return true;
  }
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
