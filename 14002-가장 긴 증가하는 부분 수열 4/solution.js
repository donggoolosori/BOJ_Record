"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  // const [n, m] = input[0].split(" ").map(Number);
  // return [n, m];
}

function solution(n, m) {
  // const ans = n+m;
  // return ans;
}

function printAnswer(ans) {
  // console.log(ans);
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, "/input/input-0.txt"), "utf-8")
    .split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
