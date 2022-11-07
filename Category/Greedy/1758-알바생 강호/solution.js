"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const n = Number(input[0]);
  const tips = input.slice(1, 1 + n).map(Number);

  return [n, tips];
}

function solution(n, tips) {
  tips.sort((a, b) => b - a);

  return tips.reduce((res, tip, idx) => {
    return res + Math.max(0, tip - idx);
  }, 0);
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
