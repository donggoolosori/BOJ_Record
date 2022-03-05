'use strict';
const fs = require('fs');

function solution(input) {
  let T = Number(input[0]);
  let readRow = 1;

  const dy = [-1, 0, 0, 1],
    dx = [0, -1, 1, 0];

  while (T--) {
    const [h, w] = input[readRow].split(' ').map(Number);

    const building = input
      .slice(readRow + 1, readRow + 1 + h)
      .map((r) => '.' + r + '.');
    let keys = input[readRow + h + 1];

    // 지도의 테두리를 빈공간으로 채우기
    let emptyStr = '';
    for (let i = 0; i < w + 2; i++) emptyStr += '.';
    building.unshift(emptyStr);
    building.push(emptyStr);

    const hasKey = Array.from({ length: 26 }, () => 0);
    // 갖고있는 key를 hasKey 배열에 체크
    keys.split('').forEach((key) => {
      hasKey[key.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    });

    // 입장가능 판별 함수
    function canEnter(x) {
      // 문일 경우
      if (x >= 'A' && x <= 'Z') {
        return;
      }

      return x !== '*';
    }

    // bfs 정의
    function bfs(sy, sx) {
      let ans = 0;

      const visit = Array.from({ length: h + 2 }, () =>
        Array.from({ length: w + 2 }, () => false)
      );
      const doorQ = Array.from({ length: 26 }, () => []);
      const q = [{ y: sy, x: sx }];
      visit[sy][sx] = true;

      while (q.length !== 0) {
        let { y, x } = q[0];
        // console.log(y, x, cnt, keyBit);
        q.shift();

        for (let i = 0; i < 4; i++) {
          const ny = y + dy[i],
            nx = x + dx[i];

          if (ny < 0 || nx < 0 || ny >= h + 2 || nx >= w + 2) continue;
          if (visit[ny][nx] || building[ny][nx] === '*') continue;

          if (building[ny][nx] >= 'A' && building[ny][nx] <= 'Z') {
            const idx = building[ny][nx].charCodeAt(0) - 'A'.charCodeAt(0);
            if (!hasKey[idx]) {
              doorQ[idx].push({ y: ny, x: nx });
              continue;
            }
          } else if (building[ny][nx] >= 'a' && building[ny][nx] <= 'z') {
            const idx = building[ny][nx].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!hasKey[idx]) {
              hasKey[idx] = true;

              while (doorQ[idx].length !== 0) {
                q.push(doorQ[idx][0]);
                doorQ[idx].shift();
              }
            }
          } else if (building[ny][nx] === '$') {
            ans++;
          }

          visit[ny][nx] = true;
          q.push({ y: ny, x: nx });
        }
      }

      return ans;
    }

    console.log(bfs(0, 0));

    // input 입력의 다음 테스트케이스로 인덱스 이동
    readRow += h + 2;
  }
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
