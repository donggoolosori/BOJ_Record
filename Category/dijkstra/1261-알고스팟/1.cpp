#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100

using namespace std;

const int INF = 2e9;
int n, m;
int maze[MAX][MAX];
int costs[MAX][MAX];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

struct Node {
  int y, x, cost;
  bool operator<(const Node &a) const { return cost > a.cost; }
};

int dijkstra() {
  costs[0][0] = 0;
  priority_queue<Node> pq;
  pq.push({0, 0, 0});

  while (!pq.empty()) {
    Node curr = pq.top();
    int y = curr.y, x = curr.x, cost = curr.cost;
    pq.pop();

    if (costs[y][x] > cost) continue;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

      if (costs[ny][nx] <= cost + maze[ny][nx]) continue;

      costs[ny][nx] = cost + maze[ny][nx];
      pq.push({ny, nx, costs[ny][nx]});
    }
  }

  return costs[n - 1][m - 1];
}

int main() {
  FAST_IO;

  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      maze[i][j] = ch - '0';
      costs[i][j] = INF;
    }
  }

  int ans = dijkstra();

  cout << ans << '\n';

  return 0;
}