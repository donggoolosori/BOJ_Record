"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const nums = input[0].split(" ").map(Number);
  return [nums];
}

function solution(nums) {
  const needs = [1, 1, 2, 2, 2, 8];

  return nums.map((num, idx) => {
    return needs[idx] - num;
  });
}

function printAnswer(ans) {
  console.log(ans.join(" "));
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, "/input/input-0.txt"), "utf-8")
    .split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
