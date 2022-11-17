"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const n = Number(input[0]);
  const prices = input.slice(1, 1 + n).map(Number);

  return [n, prices];
}

function solution(n, prices) {
  prices.sort((a, b) => b - a);

  let ret = 0;
  for (let i = 0; i < n; i += 3) {
    ret += prices[i];
    if (prices[i + 1]) ret += prices[i + 1];
  }

  return ret;
}

function printAnswer(ans) {
  console.log(ans);
}

function input() {
  const read = fs.readFileSync(path.join(__dirname, "/input/input-1.txt"), "utf-8").split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
