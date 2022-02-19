'use strict';
const fs = require('fs');

function solution(input) {
  const [n, numStr] = input;
  const arr = numStr.split(' ').map(Number);

  const lis = Array.from({ length: n }, () => 0);
  const lds = Array.from({ length: n }, () => 0);

  for (let i = 0, e = n - 1; i < n && e >= 0; i++, e--) {
    let partialLIS = 0,
      partialLDS = 0;

    for (let j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        partialLIS = Math.max(partialLIS, lis[j]);
      }
    }

    for (let j = e + 1; j < n; j++) {
      if (arr[j] < arr[e]) {
        partialLDS = Math.max(partialLDS, lds[j]);
      }
    }

    lis[i] = partialLIS + 1;
    lds[e] = partialLDS + 1;
  }
  let ans = 0;
  for (let i = 0; i < n; i++) {
    ans = Math.max(ans, lis[i] + lds[i] - 1);
  }
  console.log(ans);
}

// const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
