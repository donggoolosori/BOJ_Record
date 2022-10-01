'use strict';
const fs = require('fs');
const path = require('path');

function solution(input) {
  const nums = Number(input[0].split(' ').join(''));

  function getClockNum(num) {
    let temp = num,
      res = num;

    for (let i = 0; i < 3; i++) {
      temp = (temp % 1000) * 10 + Math.floor(temp / 1000);
      if (temp < res) res = temp;
    }

    return res;
  }

  const clockNum = getClockNum(nums);

  let count = 0;
  for (let i = 1111; i <= clockNum; i++) {
    if (getClockNum(i) === i) count++;
  }

  return count;
}

function printAnswer(ans) {
  console.log(ans);
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, '/input/input-0.txt'), 'utf-8')
    .split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

printAnswer(solution(...input()));
