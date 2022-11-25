"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const [n, k] = input[0].split(" ").map(Number);
  return [n, k];
}

function solution(n, k) {
  let sum = 0;
  for (let i = 1; i <= k; i++) {
    sum += i;
  }

  n -= sum;

  if (n < 0) {
    return -1;
  }

  if (n % k === 0) return k - 1;

  return k;
}

function printAnswer(ans) {
  console.log(ans);
}

function input() {
  const read = fs.readFileSync(path.join(__dirname, "/input/input-0.txt"), "utf-8").split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
