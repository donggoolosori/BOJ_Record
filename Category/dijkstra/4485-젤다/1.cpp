#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 125

using namespace std;

const int INF = 2e9;
int n;
int cave[MAX][MAX], costs[MAX][MAX];
struct Node {
  int y, x, cost;
  bool operator<(const Node &a) const { return cost > a.cost; }
};
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int dijkstra() {
  priority_queue<Node> pq;
  pq.push({0, 0, cave[0][0]});

  while (!pq.empty()) {
    Node curr = pq.top();
    int y = curr.y, x = curr.x, cost = curr.cost;
    pq.pop();

    if (costs[y][x] < cost) continue;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

      if (costs[ny][nx] > cost + cave[ny][nx]) {
        costs[ny][nx] = cost + cave[ny][nx];
        pq.push({ny, nx, costs[ny][nx]});
      }
    }
  }

  return costs[n - 1][n - 1];
}

int main() {
  FAST_IO;

  int index = 1;
  while (true) {
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> cave[i][j];
        costs[i][j] = INF;
      }
    }
    cout << "Problem " << index++ << ": " << dijkstra() << '\n';
  }

  return 0;
}