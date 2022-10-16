"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  return [input.slice(0, 4).map((s) => s.split(" ").map(Number))];
}

function solution(info) {
  let ret = 0,
    curr = 0;
  info.forEach(([getout, getin]) => {
    curr += getin - getout;
    ret = Math.max(ret, curr);
  });

  return ret;
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
