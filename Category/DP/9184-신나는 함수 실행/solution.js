"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  return [input.slice(0, -2).map((s) => s.split(" ").map(Number))];
}

function solution(input) {
  const dp = Array.from({ length: 101 }, () =>
    Array.from({ length: 101 }, () => Array.from({ length: 101 }, () => undefined))
  );

  const w = (a, b, c) => {
    if (dp[a][b][c] !== undefined) {
      return dp[a][b][c];
    }

    if (a <= 50 || b <= 50 || c <= 50) return (dp[a][b][c] = 1);

    if (a > 70 || b > 70 || c > 70) return (dp[a][b][c] = w(70, 70, 70));

    if (a < b && b < c) return (dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));

    return (dp[a][b][c] =
      w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));
  };

  return input.map(([a, b, c]) => {
    const ans = w(a + 50, b + 50, c + 50);
    return `w(${a}, ${b}, ${c}) = ${ans}`;
  });
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
