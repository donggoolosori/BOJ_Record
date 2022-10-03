'use strict';
const fs = require('fs');
const path = require('path');

function solution(input) {
  const N = Number(input[0]),
    M = Number(input[2]);
  const std = input[1].split(' ').join('');

  const seqs = input.slice(3, 3 + M).map((s) => s.split(' ').join(''));

  function isSameShape(a, b) {
    if (a.length !== b.length) return false;

    for (let i = 0; i < b.length; i++) {
      if (a === b) return true;

      b = b.substring(1) + b[0];
    }
    return false;
  }
  return seqs
    .filter((seq) => {
      const rseq = seq
        .split('')
        .reverse()
        .map((s) => {
          if (s === '1') {
            return '3';
          } else if (s === '2') {
            return '4';
          } else if (s === '3') {
            return '1';
          } else if (s === '4') {
            return '2';
          }
        })
        .join('');

      return isSameShape(std, seq) || isSameShape(std, rseq);
    })
    .map((seq) => seq.split('').join(' '));
}

function printAnswer(ans) {
  console.log(ans.length);
  ans.forEach((s) => console.log(s));
}

function input() {
  const read = fs
    .readFileSync(path.join(__dirname, '/input/input-0.txt'), 'utf-8')
    .split('\n');
  // const read = fs.readFileSync(0, 'utf-8').split('\n');

  return [read];
}

printAnswer(solution(...input()));
