"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  return [Number(input[0])];
}

function solution(n) {
  return n % 2 === 0 ? "CY" : "SK";
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
