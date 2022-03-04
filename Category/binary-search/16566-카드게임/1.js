'use strict';
const fs = require('fs');

function upperBound(arr, target) {
  let low = 0,
    high = arr.length - 1;

  while (low < high) {
    const mid = parseInt((low + high) / 2);

    if (arr[mid] <= target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return arr[low] > target ? low : low + 1;
}

function getParent(parent, x) {
  if (x === parent[x]) return x;

  return (parent[x] = getParent(parent, parent[x]));
}

function unionParent(parent, a, b) {
  a = getParent(parent, a);
  b = getParent(parent, b);

  if (a < b) {
    const temp = a;
    a = b;
    b = temp;
  }

  parent[b] = a;
}

function solution(input) {
  const [N, M, K] = input[0].split(' ').map(Number);
  const cards = input[1].split(' ').map(Number);
  const game = input[2].split(' ').map(Number);

  const parent = Array.from({ length: M }, (_, idx) => idx);

  cards.sort((a, b) => a - b);

  const ans = game.reduce((prev, card) => {
    const biggerIdx = getParent(parent, upperBound(cards, card));

    const nextCard = cards[biggerIdx];

    unionParent(parent, biggerIdx, biggerIdx + 1);

    return prev + nextCard + '\n';
  }, '');

  console.log(ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
