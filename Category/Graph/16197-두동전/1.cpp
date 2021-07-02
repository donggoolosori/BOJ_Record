#include <iostream>
#include <queue>

using namespace std;

int n, m, sy1, sx1, sy2, sx2;
char board[20][20];
int visit[20][20][20][20];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
struct Node {
  int y1, x1, y2, x2, dist;
};

bool isOut(int y, int x) { return (y < 0 || x < 0 || y >= n || x >= m); }

int bfs() {
  queue<Node> q;
  q.push({sy1, sx1, sy2, sx2, 0});

  while (!q.empty()) {
    Node curr = q.front();
    int y1 = curr.y1, x1 = curr.x1, y2 = curr.y2, x2 = curr.x2,
        dist = curr.dist;
    q.pop();

    // over 10 times
    if (dist > 10) return -1;
    // coins are at the same position
    if (y1 == y2 && x1 == x2) continue;
    // two coins are out
    if (isOut(curr.y1, curr.x1) && isOut(curr.y2, curr.x2)) continue;
    // one coin is out : success
    if (isOut(curr.y1, curr.x1) || isOut(curr.y2, curr.x2)) return dist;
    // visit check
    if (visit[y1][x1][y2][x2]) continue;
    visit[y1][x1][y2][x2] = true;

    for (int i = 0; i < 4; i++) {
      int ny1 = y1 + dy[i], nx1 = x1 + dx[i], ny2 = y2 + dy[i],
          nx2 = x2 + dx[i];

      // (ny1, nx1) is blocked by #
      if (ny1 >= 0 && nx1 >= 0 && ny1 < n && nx1 < m &&
          board[ny1][nx1] == '#') {
        ny1 = y1, nx1 = x1;
      }
      // (ny2, nx2) is blocked by #
      if (ny2 >= 0 && nx2 >= 0 && ny2 < n && nx2 < m &&
          board[ny2][nx2] == '#') {
        ny2 = y2, nx2 = x2;
      }
      q.push({ny1, nx1, ny2, nx2, dist + 1});
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input
  bool flag = false;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      // set coins' init position
      if (board[i][j] == 'o') {
        if (!flag) {
          flag = true;
          sy1 = i, sx1 = j;
        } else {
          sy2 = i, sx2 = j;
        }
      }
    }
  }

  cout << bfs();

  return 0;
}