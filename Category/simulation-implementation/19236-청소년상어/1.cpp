#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int ans = 0;

void dfs(vector<vector<PII>> map, vector<PII> pos, int sy, int sx, int sd,
         int eat) {
  int fishNum, fishDir;
  tie(fishNum, fishDir) = map[sy][sx];

  if (fishNum != 0) {
    eat += fishNum;
    sd = fishDir;

    pos[fishNum] = {-1, -1};
    map[sy][sx] = {0, 0};
  }

  ans = max(ans, eat);

  for (int i = 1; i <= 16; i++) {
    int y, x;
    tie(y, x) = pos[i];

    if (y == -1) continue;

    int d = map[y][x].second;

    for (int j = 0; j < 8; j++) {
      int nd = (d + j) % 8;
      int ny = y + dy[nd], nx = x + dx[nd];

      map[y][x].second = nd;

      if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
      if (ny == sy && nx == sx) continue;

      pos[i] = {ny, nx};

      pos[map[ny][nx].first] = {y, x};
      swap(map[y][x], map[ny][nx]);

      break;
    }
  }

  int dist = 1;
  while (true) {
    int ny = sy + dy[sd] * dist, nx = sx + dx[sd] * dist;
    dist++;
    if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) break;

    if (map[ny][nx].first != 0) {
      dfs(map, pos, ny, nx, sd, eat);
    }
  }
}

int main() {
  FAST_IO;

  vector<PII> pos(17);
  vector<vector<PII>> map(4, vector<PII>(4));

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int num, d;
      cin >> num >> d;
      pos[num] = {i, j};
      map[i][j] = {num, d - 1};
    }
  }

  dfs(map, pos, 0, 0, 0, 0);

  cout << ans << '\n';

  return 0;
}