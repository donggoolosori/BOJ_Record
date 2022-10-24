"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const t = Number(input[0]);
  const inputs = input.slice(1, -1).map((s) => s.split(" ").map(Number));

  return [t, inputs];
}

function solution(t, inputs) {
  let read = 0;
  while (t--) {
    const [v, e] = inputs[read];
    const graph = Array.from({ length: v + 1 }, () => Array.from({ length: v + 1 }, () => false));
    for (let i = read + 1; i <= read + e; i++) {
      const [u, v] = inputs[i];
      graph[u][v] = true;
      graph[v][u] = true;
    }
    read += e + 1;
  }
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
