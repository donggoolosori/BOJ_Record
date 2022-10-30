"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  const T = Number(input[0]);
  const inputs = [];

  for (let i = 0; i < T; i++) {
    const n = Number(input[i * 2 + 1]);
    const prices = input[i * 2 + 2].split(" ").map(Number);
    inputs.push({ n, prices });
  }

  return [inputs];
}

function solution(inputs) {
  const res = [];

  for (const input of inputs) {
    let income = 0,
      max = 0;
    const { n, prices } = input;

    for (let i = n - 1; i >= 0; i--) {
      if (prices[i] > max) {
        max = prices[i];
      }
      income += max - prices[i];
    }

    res.push(income);
  }

  return res;
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
