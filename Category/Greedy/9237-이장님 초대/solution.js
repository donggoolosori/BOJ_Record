"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const N = Number(input[0]);
  const days = input[1].split(" ").map(Number);
  return [N, days];
}

function solution(n, days) {
  days.sort((a, b) => b - a);

  return days.reduce((max, day, idx) => Math.max(max, 2 + idx + day), 1);
}

function printAnswer(ans) {
  console.log(ans);
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, "/input/input-0.txt"), "utf-8")
    .split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
