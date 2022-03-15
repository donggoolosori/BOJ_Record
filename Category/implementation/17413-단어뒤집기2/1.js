'use strict';
const fs = require('fs');

function solution(input) {
  const str = input[0];

  let ans = '',
    temp = '';

  for (let i = 0; i < str.length; i++) {
    if (str[i] === '<') {
      ans += temp.reverse();
      temp = '';
      while (str[i] !== '>') {
        ans += str[i++];
      }

      ans += '>';
    } else if (str[i] === ' ') {
      ans += temp.reverse() + ' ';
      temp = '';
    } else {
      temp += str[i];
    }
  }

  if (temp.length !== 0) {
    ans += temp.reverse();
  }

  console.log(ans);
}

String.prototype.reverse = function () {
  return this.split('').reverse().join('');
};

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
