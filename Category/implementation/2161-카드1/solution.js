"use strict";
const fs = require("fs");
const path = require("path");

function refineInput(input) {
  return [input[0]];
}

function solution(N) {
  const ret = [];

  const cards = Array.from({ length: N }, (_, idx) => idx + 1);

  while (cards.length) {
    if (cards.length === 1) {
      ret.push(cards[0]);
      break;
    }
    // 위 버리고
    ret.push(cards.shift());
    // 위 맨뒤로
    cards.push(cards.shift());
  }

  return ret;
}

function printAnswer(ans) {
  console.log(ans.join(" "));
}

function input() {
  const read = fs.readFileSync(path.join(__dirname, "/input/input-0.txt"), "utf-8").split("\n");
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return read;
}

printAnswer(solution(...refineInput(input())));
