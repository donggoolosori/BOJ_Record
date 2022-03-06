#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define INF 987654321
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1500
#define pii pair<int, int>

using namespace std;

int r, c, dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};
bool visit[MAX][MAX];
char lake[MAX][MAX];
pii parent[MAX][MAX];
pii swan1 = {-1, -1}, swan2;
queue<pii> q, nq;

pii getParent(pii x) {
  int i, j;
  tie(i, j) = x;

  if (parent[i][j] == x) return x;

  return parent[i][j] = getParent(parent[i][j]);
}

void unionParent(pii a, pii b) {
  a = getParent(a);
  b = getParent(b);

  if (a > b) swap(a, b);

  parent[b.first][b.second] = a;
}

bool compareParent(pii a, pii b) {
  a = getParent(a);
  b = getParent(b);

  return a == b;
}

void melt() {
  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    if (visit[y][x]) continue;
    visit[y][x] = true;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
      if (visit[ny][nx]) continue;

      if (lake[ny][nx] == 'X') {
        nq.push({ny, nx});
        lake[ny][nx] = '.';
        for (int j = 0; j < 4; j++) {
          int nny = ny + dy[i], nnx = nx + dx[i];
          if (nny < 0 || nnx < 0 || nny >= r || nnx >= c) continue;
          if (lake[nny][nnx] == 'X') continue;
          unionParent({ny, nx}, {nny, nnx});
        }
      }
      unionParent({y, x}, {ny, nx});
    }
  }

  q = nq;
  while (!nq.empty()) nq.pop();
}

int main() {
  FAST_IO;

  cin >> r >> c;

  // parent 초기화
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      parent[i][j] = {i, j};
    }
  }
  // 입력받기
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> lake[i][j];
      if (lake[i][j] == 'L') {
        if (swan1.first == -1) {
          swan1.first = i, swan1.second = j;
        } else {
          swan2.first = i, swan2.second = j;
        }
      }
      if (lake[i][j] != 'X') {
        q.push({i, j});
      }
    }
  }

  int day = 0;

  while (true) {
    if (compareParent(swan1, swan2)) {
      cout << day << '\n';
      break;
    }

    melt();

    day++;
  }

  return 0;
}