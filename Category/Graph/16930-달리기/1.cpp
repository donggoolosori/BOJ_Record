// 84ms
#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

const int INF = 2e9;
int n, m, k, fr_y, fr_x, to_y, to_x;
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
char gym[MAX + 1][MAX + 1];
int visit[MAX + 1][MAX + 1];
struct Node {
  int y, x, time;
};

inline void getInput() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> gym[i][j];
      visit[i][j] = INF;
    }
  }
  cin >> fr_y >> fr_x >> to_y >> to_x;
}

int getMinTime() {
  queue<Node> q;
  q.push({fr_y, fr_x, 0});
  visit[fr_y][fr_x] = 0;

  while (!q.empty()) {
    Node curr = q.front();
    int y = curr.y, x = curr.x, time = curr.time;
    q.pop();

    if (y == to_y && x == to_x) {
      return time;
    }
    for (int d = 0; d < 4; d++) {
      for (int j = 1; j <= k; j++) {
        int ny = y + dy[d] * j, nx = x + dx[d] * j;
        if (ny <= 0 || nx <= 0 || ny > n || nx > m) break;
        if (gym[ny][nx] == '#') break;
        if (visit[ny][nx] == INF) {
          visit[ny][nx] = time + 1;
          q.push({ny, nx, time + 1});
        } else if (visit[ny][nx] == time + 1)
          continue;
        else
          break;
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getInput();

  cout << getMinTime() << '\n';
  return 0;
}