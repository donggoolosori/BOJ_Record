"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const [N, L] = input[0].split(" ").map(Number);
  const heights = input[1].split(" ").map(Number);

  return [N, L, heights];
}

function solution(N, L, heights) {
  heights.sort((a, b) => a - b);

  return heights.reduce((len, h) => {
    if (len < h) return len;
    return len + 1;
  }, L);
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
