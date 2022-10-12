"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const n = Number(input[0]);
  const assignments = input.slice(1, 1 + n).map((r) => {
    const [d, w] = r.split(" ").map(Number);
    return { d, w };
  });
  return [n, assignments];
}

function solution(n, assignments) {
  assignments.sort((a, b) => {
    if (a.w === b.w) {
      return a.d - b.d;
    }
    return b.w - a.w;
  });

  const scores = Array.from({ length: n + 1 }, () => 0);

  assignments.forEach(({ d, w }) => {
    while (scores[d] !== 0 && d > 0) {
      d--;
    }
    if (d === 0) return;
    scores[d] = w;
  });

  return scores.reduce((acc, score) => acc + score);
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
