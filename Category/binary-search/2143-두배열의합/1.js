'use strict';
const fs = require('fs');

function solution(input) {
  const T = Number(input[0]);

  const A = input[2].split(' ').map(Number);
  const B = input[4].split(' ').map(Number);

  const sumA = [],
    sumB = [];

  for (let i = 0; i < A.length; i++) {
    let sum = 0;
    for (let j = i; j < A.length; j++) {
      sum += A[j];

      sumA.push(sum);
    }
  }

  for (let i = 0; i < B.length; i++) {
    let sum = 0;
    for (let j = i; j < B.length; j++) {
      sum += B[j];

      sumB.push(sum);
    }
  }

  sumA.sort((a, b) => a - b);
  sumB.sort((a, b) => a - b);

  let ans = 0;

  sumA.forEach((a) => {
    const low = lowerBound(sumB, T - a);
    const high = upperBound(sumB, T - a);

    ans += high - low;
  });

  console.log(ans);
}

function lowerBound(arr, target) {
  let low = 0,
    high = arr.length - 1;

  while (low < high) {
    const mid = parseInt((low + high) / 2);

    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return arr[low] >= target ? low : low + 1;
}

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

  return arr[low] > target ? low : arr.length;
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
