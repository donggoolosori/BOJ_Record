#include <iostream>
#include <queue>

using namespace std;

int n, m;
char maps[101][101];
bool visit[101][101];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
struct Node {
  int y, x, dist;
};

int bfs() {
  visit[1][1] = true;
  queue<Node> q;
  q.push({1, 1, 1});

  while (!q.empty()) {
    Node curr = q.front();
    int y = curr.y, x = curr.x, dist = curr.dist;
    q.pop();

    if (y == n && x == m) return dist;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny <= 0 || nx <= 0 || ny > n || nx > m) continue;
      if (visit[ny][nx] || maps[ny][nx] == '0') continue;
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
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> maps[i][j];

  cout << bfs() << '\n';

  return 0;
}