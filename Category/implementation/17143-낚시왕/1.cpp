#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define FOR(i, s, e) for (int i = s; i < e; i++)
#define INF 987654321
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MAX 100

using namespace std;

struct Shark {
  int y, x, s, d, z;
};
int R, C, M, sum;
const int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<Shark> fishing[MAX + 1][MAX + 1];

void catchShark(int col) {
  FOR(i, 1, R + 1) {
    if (fishing[i][col].size() > 0) {
      sum += fishing[i][col][0].z;
      fishing[i][col].clear();
      break;
    }
  }
}

int main() {
  FAST_IO;

  cin >> R >> C >> M;

  FOR(i, 0, M) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    fishing[r][c].push_back({r, c, s, d, z});
  }

  int curr = 0;

  while (curr++ < C) {
    catchShark(curr);

    vector<Shark> newFishing[MAX + 1][MAX + 1];

    // 상어 이동
    FOR(i, 1, R + 1) {
      FOR(j, 1, C + 1) {
        if (fishing[i][j].empty()) continue;

        Shark shark = fishing[i][j][0];
        fishing[i][j].pop_back();

        int s;
        if (shark.d == 1 || shark.d == 2) {
          s = shark.s % ((R - 1) * 2);
        } else {
          s = shark.s % ((C - 1) * 2);
        }

        int ny = shark.y, nx = shark.x, nd = shark.d;

        while (s--) {
          if (nd == 1 && ny == 1) {
            nd = 2;
          } else if (nd == 2 && ny == R) {
            nd = 1;
          } else if (nd == 3 && nx == C) {
            nd = 4;
          } else if (nd == 4 && nx == 1) {
            nd = 3;
          }

          int dy = dir[nd][0], dx = dir[nd][1];
          ny += dy, nx += dx;
        }

        shark.y = ny, shark.x = nx, shark.d = nd;

        if (newFishing[ny][nx].empty()) {
          newFishing[ny][nx].push_back(shark);
        } else {
          if (newFishing[ny][nx][0].z < shark.z) {
            newFishing[ny][nx][0] = shark;
          }
        }
      }
    }

    FOR(i, 1, R + 1) {
      FOR(j, 1, C + 1) { fishing[i][j] = newFishing[i][j]; }
    }
  }

  cout << sum << '\n';

  return 0;
}