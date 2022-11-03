"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const [n, m] = input[0].split(" ").map(Number);
  const j = Number(input[1]);

  const apples = input.slice(2, 2 + j).map(Number);
  return [n, m, apples];
}

function solution(n, m, apples) {
  let s = 1,
    e = m;
  return apples.reduce((res, pos) => {
    if (pos > e) {
      const move = pos - e;
      s += move;
      e += move;
      return res + move;
    } else if (pos < s) {
      const move = s - pos;
      s -= move;
      e -= move;
      return res + move;
    }
    return res;
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
