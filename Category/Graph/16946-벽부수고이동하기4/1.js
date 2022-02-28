'use strict';
const fs = require('fs');

function solution(input) {
  const [n, m] = input[0].split(' ').map(Number);

  const map = input.slice(1, n + 1).map((str) => str.split('').map(Number));

  let visit = Array.from({ length: n }, () =>
    Array.from({ length: m }, () => false)
  );

  const area = Array.from({ length: n }, () =>
    Array.from({ length: m }, () => 0)
  );

  const dy = [-1, 0, 0, 1],
    dx = [0, -1, 1, 0];

  function dfs(y, x, areaNum) {
    area[y][x] = areaNum;
    visit[y][x] = true;

    let ret = 1;

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i],
        nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (visit[ny][nx] || map[ny][nx] === 1) continue;

      ret += dfs(ny, nx, areaNum);
    }

    return ret;
  }

  let areaNum = 1;

  const areaMap = {};

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (map[i][j] !== 0 || visit[i][j]) continue;

      const cnt = dfs(i, j, areaNum);

      areaMap[areaNum++] = cnt % 10;
    }
  }

  const ans = [];

  for (let i = 0; i < n; i++) {
    let row = '';

    for (let j = 0; j < m; j++) {
      if (map[i][j] === 0) {
        row += '0';
        continue;
      }

      let cnt = 1;
      visit = {};

      for (let d = 0; d < 4; d++) {
        const ny = i + dy[d],
          nx = j + dx[d];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (map[ny][nx] === 1) continue;

        const areaNum = area[ny][nx];

        if (visit[areaNum]) continue;
        visit[areaNum] = true;
        cnt += areaMap[areaNum];
      }

      row += cnt % 10;
    }

    ans.push(row);
  }

  console.log(ans.reduce((prev, curr) => prev + curr + '\n', ''));
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
