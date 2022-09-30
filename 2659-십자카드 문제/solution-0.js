'use strict';
const fs = require('fs');
const path = require('path');

function solution(input) {
  const nums = input[0].split(' ').join('');

  let clockNum = nums;
  let temp = nums;
  for (let i = 0; i < 3; i++) {
    temp = temp.slice(1) + temp[0];
    if (Number(clockNum) > Number(temp)) {
      clockNum = temp;
    }
  }

  let flag = false,
    count = 0;

  function dfs(L = 0, idx = 1, num = '') {
    if (flag) return;

    if (L === 4) {
      count++;
      console.log(num);

      if (num === clockNum) {
        flag = true;
      }
      return;
    }
    for (let i = idx; i <= 9; i++) {
      dfs(L + 1, i, num + i);
    }
  }
  dfs();

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
