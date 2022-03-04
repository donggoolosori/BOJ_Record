'use strict';
const fs = require('fs');

function solution(input) {
  const [N, M, K] = input[0].split(' ').map(Number);

  const nums = input.slice(1, 1 + N).map(Number);
  const queries = input.slice(1 + N).map((str) => str.split(' ').map(Number));
  const tree = [0];

  function init(start, end, node) {
    if (start === end) return (tree[node] = nums[start]);

    const mid = parseInt((start + end) / 2);

    return (tree[node] =
      init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1));
  }

  function getPartialSum(start, end, node, left, right) {
    if (left > end || right < start) return 0;

    if (left <= start && end <= right) return tree[node];

    const mid = parseInt((start + end) / 2);

    return (
      getPartialSum(start, mid, node * 2, left, right) +
      getPartialSum(mid + 1, end, node * 2 + 1, left, right)
    );
  }

  function update(start, end, node, updateIdx, diff) {
    if (updateIdx < start || updateIdx > end) return;

    if (start <= updateIdx && updateIdx <= end) tree[node] += diff;

    if (start === end) return;

    const mid = parseInt((start + end) / 2);

    update(start, mid, node * 2, updateIdx, diff);
    update(mid + 1, end, node * 2 + 1, updateIdx, diff);
  }

  init(0, N - 1, 1);

  const ans = queries.reduce((prev, q) => {
    if (q[0] === 1) {
      const [_, updateIdx, newVal] = q;

      const diff = newVal - nums[updateIdx - 1];
      nums[updateIdx - 1] = newVal;
      update(0, N - 1, 1, updateIdx - 1, diff);

      return prev;
    }

    const [_, left, right] = q;

    const partialSum = getPartialSum(0, N - 1, 1, left - 1, right - 1);

    return prev + partialSum + '\n';
  }, '');

  console.log(ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
