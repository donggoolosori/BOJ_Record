#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
int n = 12, m = 6;
char puyo[12][6];
bool visit[12][6];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int getConnectedPuyo(int y, int x, char color) {
  int ret = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
    if (visit[ny][nx] || color != puyo[ny][nx]) continue;
    visit[ny][nx] = true;
    ret += getConnectedPuyo(ny, nx, color);
    visit[ny][nx] = false;
  }

  return ret;
}

void erasePuyo(int y, int x, char color) {
  puyo[y][x] = '.';

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
    if (visit[ny][nx] || color != puyo[ny][nx]) continue;
    visit[ny][nx] = true;
    erasePuyo(ny, nx, color);
    visit[ny][nx] = false;
  }
}

bool poping() {
  bool poped = false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (puyo[i][j] == '.') continue;
      visit[i][j] = true;
      if (getConnectedPuyo(i, j, puyo[i][j]) >= 4) {
        poped = true;
        erasePuyo(i, j, puyo[i][j]);
      }
      visit[i][j] = false;
    }
  }

  return poped;
}

void workGravity() {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (puyo[i][j] == '.') continue;

      int swapIdx = i;
      for (int k = i + 1; k < n; k++) {
        if (puyo[k][j] != '.') break;
        swapIdx++;
      }
      swap(puyo[swapIdx][j], puyo[i][j]);
    }
  }
}

int main() {
  FAST_IO;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> puyo[i][j];
    }
  }

  int cnt = 0;

  while (true) {
    if (!poping()) {
      break;
    }
    workGravity();
    cnt++;
  }

  cout << cnt << '\n';

  return 0;
}