#include <iostream>
#include <queue>

using namespace std;

int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
int n, m, sy1 = -1, sx1 = -1, sy2, sx2;
char board[20][20];
struct State {
  int y1, x1, y2, x2, dist;
};
bool visit[20][20][20][20];

bool outOfRange(int y, int x) { return y < 0 || x < 0 || y >= n || x >= m; }

int getMinTime() {
  queue<State> q;
  q.push({sy1, sx1, sy2, sx2, 0});

  while (!q.empty()) {
    State curr = q.front();
    int y1 = curr.y1, x1 = curr.x1, x2 = curr.x2, y2 = curr.y2,
        dist = curr.dist;
    q.pop();

    if (dist > 10) return -1;
    // 둘다 나간 경우
    if (outOfRange(y1, x1) && outOfRange(y2, x2)) continue;
    // 동전이 겹친 경우
    if (y1 == y2 && x1 == x2) continue;
    // 성공
    if ((outOfRange(y1, x1) || outOfRange(y2, x2))) return dist;

    // 이미 방문한적 있는 경우
    if (visit[y1][x1][y2][x2]) continue;
    visit[y1][x1][y2][x2] = true;

    for (int i = 0; i < 4; i++) {
      int ny1 = y1 + dy[i], nx1 = x1 + dx[i], ny2 = y2 + dy[i],
          nx2 = x2 + dx[i];

      // 첫번째 동전 벽에 막힌 경우
      if (!outOfRange(ny1, nx1) && board[ny1][nx1] == '#') ny1 = y1, nx1 = x1;
      // 두번째 동전 벽에 막힌 경우
      if (!outOfRange(ny2, nx2) && board[ny2][nx2] == '#') ny2 = y2, nx2 = x2;

      q.push({ny1, nx1, ny2, nx2, dist + 1});
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'o') {
        if (sy1 == -1) {
          sy1 = i, sx1 = j;
        } else {
          sy2 = i, sx2 = j;
        }
      }
    };

  cout << getMinTime() << '\n';

  return 0;
}