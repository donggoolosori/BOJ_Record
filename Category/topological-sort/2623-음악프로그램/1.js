'use strict';

const fs = require('fs');
const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

const [n, m] = input[0].split(' ').map((v) => Number(v));
const graph = Array.from({ length: n + 1 }, () => []);

function solution() {
  const inDegree = Array.from({ length: n + 1 }, () => 0);

  for (let i = 1; i <= m; i++) {
    const order = input[i].split(' ').map((v) => Number(v));

    for (let j = 1; j < order[0]; j++) {
      graph[order[j]].push(order[j + 1]);
      inDegree[order[j + 1]]++;
    }
  }

  const q = [];
  for (let i = 1; i <= n; i++) {
    if (inDegree[i] !== 0) continue;

    q.push(i);
  }

  const order = [];

  for (let i = 1; i <= n; i++) {
    if (q.length === 0) {
      console.log(0);
      return;
    }
    const curr = q[0];
    q.shift();

    order.push(curr);

    for (const next of graph[curr]) {
      if (--inDegree[next] === 0) {
        q.push(next);
      }
    }
  }

  const answer = order.reduce((prev, curr) => prev + curr + '\n', '');

  console.log(answer);
}

solution();
