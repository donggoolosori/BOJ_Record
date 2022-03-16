'use strict';
const fs = require('fs');

function solution(input) {
  const [N, M, D] = input[0].split(' ').map(Number);
  const dy = [0, -1, 0],
    dx = [-1, 0, 1];
  const map = input.slice(1).map((s) => s.split(' ').map(Number));

  let ans = 0,
    enemies = 0;

  function attack(arc1, arc2, arc3, arcRow, map) {
    const visit = Array.from({ length: 3 }, () =>
      Array.from({ length: N }, () => Array.from({ length: M }, () => false))
    );
    const q = [];
    q.push({ y: arcRow - 1, x: arc1, dist: 1, arcNum: 0 });
    q.push({ y: arcRow - 1, x: arc2, dist: 1, arcNum: 1 });
    q.push({ y: arcRow - 1, x: arc3, dist: 1, arcNum: 2 });
    visit[0][arcRow - 1][arc1] = true;
    visit[1][arcRow - 1][arc2] = true;
    visit[2][arcRow - 1][arc3] = true;

    const killed = {};
    const killPos = [];

    while (q.length !== 0) {
      const { y, x, dist, arcNum } = q[0];
      q.shift();

      if (killed[arcNum]) continue;

      if (map[y][x] === 1) {
        killed[arcNum] = true;
        killPos.push({ y, x });
        continue;
      }

      if (dist === D) continue;

      for (let i = 0; i < 3; i++) {
        const ny = y + dy[i],
          nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visit[arcNum][ny][nx]) continue;
        visit[arcNum][ny][nx] = true;

        q.push({ y: ny, x: nx, dist: dist + 1, arcNum });
      }
    }

    let killCount = 0;

    killPos.forEach(({ y, x }) => {
      if (map[y][x] === 1) {
        map[y][x] = 0;
        killCount++;
        enemies--;
      }
    });

    return killCount;
  }

  function copy() {
    const copyMap = [...map];
    return copyMap.map((_, idx) => [...map[idx]]);
  }

  let enemiesNum = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (map[i][j] === 1) enemiesNum++;
    }
  }

  for (let arc1 = 0; arc1 < M; arc1++) {
    for (let arc2 = arc1 + 1; arc2 < M; arc2++) {
      for (let arc3 = arc2 + 1; arc3 < M; arc3++) {
        let cnt = 0,
          arcRow = N;
        const copyMap = copy();

        enemies = enemiesNum;

        while (enemies > 0 && arcRow > 0) {
          cnt += attack(arc1, arc2, arc3, arcRow, copyMap);
          arcRow--;
          for (let i = 0; i < M; i++) {
            if (copyMap[arcRow][i] === 1) {
              enemies--;
            }
          }
        }

        ans = Math.max(ans, cnt);
      }
    }
  }

  console.log(ans);
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
