"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const n = Number(input[0]);
  const expected = input.slice(1, 1 + n).map(Number);

  return [n, expected];
}

function solution(n, expected) {
  expected.sort((a, b) => a - b);

  return expected.reduce((res, exp, idx) => res + Math.abs(exp - (idx + 1)), 0);
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
