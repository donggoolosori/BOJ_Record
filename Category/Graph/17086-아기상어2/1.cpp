#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maps[50][50], visit[50][50];
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct Node {
  int y, x, dist;
};

int bfs(int sy, int sx) {
  visit[sy][sx] = true;
  queue<Node> q;
  q.push({sy, sx, 0});

  while (!q.empty()) {
    int y = q.front().y, x = q.front().x, dist = q.front().dist;
    q.pop();

    if (maps[y][x] == 1) return dist;

    for (int i = 0; i < 8; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (visit[ny][nx]) continue;
      visit[ny][nx] = true;
      q.push({ny, nx, dist + 1});
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> maps[i][j];
    }
  }

  int answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maps[i][j] == 1) continue;
      memset(visit, 0, sizeof(visit));
      answer = max(answer, bfs(i, j));
    }
  }
  cout << answer;

  return 0;
}