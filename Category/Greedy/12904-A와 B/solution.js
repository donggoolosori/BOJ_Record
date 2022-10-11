"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  return input;
}

function solution(s, t) {
  while (s.length !== t.length) {
    const backword = t[t.length - 1];

    if (backword === "A") {
      t = t.substring(0, t.length - 1);
    } else if (backword === "B") {
      t = t.substring(0, t.length - 1);

      t = t.split("").reverse().join("");
    }
  }

  if (s === t) {
    return 1;
  }
  return 0;
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
