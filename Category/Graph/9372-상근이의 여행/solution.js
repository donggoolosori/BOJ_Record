"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const t = Number(input[0]);
  const inputArr = input.slice(1, -1).map((s) => s.split(" ").map(Number));

  return [t, inputArr];
}

function solution(t, info) {
  let start = 0;
  const ret = [];

  while (t--) {
    const [n, m] = info[start];
    start += m + 1;

    ret.push(n - 1);
  }

  return ret;
}

function printAnswer(ans) {
  console.log(ans.join("\n"));
}

function input() {
  const read = fs.readFileSync(path.join(__dirname, "/input/input-0.txt"), "utf-8").split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
