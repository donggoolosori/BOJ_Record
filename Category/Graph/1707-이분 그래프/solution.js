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
    const graph = Array.from({ length: v + 1 }, () => []);
    const visited = Array.from({ length: v + 1 }, () => 0);

    for (let i = read + 1; i <= read + e; i++) {
      const [u, v] = inputs[i];
      graph[u].push(v);
      graph[v].push(u);
    }
    read += e + 1;

    function dfs(cur) {
      if (!visited[cur]) visited[cur] = 1;

      graph[cur].forEach((next) => {
        if (visited[next]) return;

        if (visited[cur] === 1) {
          visited[next] = 2;
        } else if (visited[cur] === 2) {
          visited[next] = 1;
        }
        dfs(next);
      });
    }
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
