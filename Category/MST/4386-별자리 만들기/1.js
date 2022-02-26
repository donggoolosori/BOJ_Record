'use strict';
const fs = require('fs');

function getDist(pos1, pos2) {
  return Math.sqrt(
    Math.pow(pos1[0] - pos2[0], 2) + Math.pow(pos1[1] - pos2[1], 2)
  );
}

function getParent(x, parent) {
  if (x === parent[x]) return x;
  return (parent[x] = getParent(parent[x], parent));
}

function unionParent(a, b, parent) {
  a = getParent(a, parent);
  b = getParent(b, parent);

  if (a === b) return false;

  if (a > b) {
    const temp = a;
    a = b;
    b = temp;
  }

  parent[b] = a;

  return true;
}

function solution(input) {
  const n = Number(input[0]);
  const pos = input.slice(1, n + 1).map((str) => str.split(' ').map(Number));
  const parent = Array.from({ length: n }, (_, idx) => idx);
  const edges = [];

  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      edges.push({ fr: i, to: j, dist: getDist(pos[i], pos[j]) });
    }
  }

  let ans = 0;

  edges.sort((a, b) => a.dist - b.dist);

  edges.forEach((edge) => {
    if (!unionParent(edge.fr, edge.to, parent)) {
      return;
    }

    ans += edge.dist;
  });

  console.log(ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
