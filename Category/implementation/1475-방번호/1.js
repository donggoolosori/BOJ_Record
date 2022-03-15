'use strict';
const fs = require('fs');

function solution(input) {
  const N = input[0];

  const numMap = {};

  let set = 0;

  for (let i = 0; i <= 8; i++) numMap[i] = 0;

  function addNumSet() {
    set++;
    for (let i = 0; i <= 8; i++) {
      if (i === 6) numMap[i]++;
      numMap[i]++;
    }
  }

  addNumSet();

  for (let i = 0; i < N.length; i++) {
    let num = N[i];
    if (num == 9) num = 6;

    if (numMap[num] == 0) {
      addNumSet();
    }
    numMap[num]--;
  }

  console.log(set);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
