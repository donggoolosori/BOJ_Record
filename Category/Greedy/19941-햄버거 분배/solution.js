"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const [n, k] = input[0].split(" ").map(Number);
  const s = input[1];
  return [n, k, s];
}

function solution(n, k, s) {
  const arr = s.split("");
  let ret = 0;

  for (let i = 0; i < n; i++) {
    if (["H", "O"].includes(arr[i])) continue;

    for (let j = Math.max(0, i - k); j <= Math.min(n - 1, i + k); j++) {
      if (arr[j] === "H") {
        arr[j] = "O";
        ret++;
        break;
      }
    }
  }

  return ret;
}

function printAnswer(ans) {
  console.log(ans);
}

function input() {
  const read = fs.readFileSync(path.join(__dirname, "/input/input-1.txt"), "utf-8").split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
