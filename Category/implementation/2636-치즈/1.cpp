#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100
#define PII pair<int, int>

using namespace std;

bool visit[MAX][MAX];
int plate[MAX][MAX];
int n, m;
int totalCheese = 0;
int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};

int bfs() {
  memset(visit, false, sizeof(visit));

  int melted = 0;

  queue<PII> q;
  q.push({0, 0});
  visit[0][0] = true;

  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (visit[ny][nx]) continue;

      visit[ny][nx] = true;

      if (plate[ny][nx] == 1) {
        plate[ny][nx] = 0;
        melted++;
        totalCheese--;
      } else {
        q.push({ny, nx});
      }
    }
  }

  return melted;
}

int main() {
  FAST_IO;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> plate[i][j];
      totalCheese += plate[i][j];
    }
  }

  int hour = 0;
  while (true) {
    hour++;
    int melted = bfs();

    if (totalCheese == 0) {
      cout << hour << '\n' << melted << '\n';
      break;
    }
  }

  return 0;
}