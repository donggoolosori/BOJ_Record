#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n;
int r1, c1, r2, c2;
bool visit[200][200];
int dy[6] = {-2, -2, 0, 0, 2, 2}, dx[6] = {-1, 1, -2, 2, -1, 1};

struct Node {
  int y, x, cnt;
};

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin >> r1 >> c1 >> r2 >> c2;
}

int bfs() {
  queue<Node> q;
  q.push({r1, c1, 0});

  while (!q.empty()) {
    int y = q.front().y, x = q.front().x, cnt = q.front().cnt;
    q.pop();

    if (y == r2 && x == c2) {
      return cnt;
    }

    for (int i = 0; i < 6; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
        continue;
      }
      if (visit[ny][nx]) continue;
      visit[ny][nx] = true;

      q.push({ny, nx, cnt + 1});
    }
  }

  return -1;
}

int main() {
  input();
  cout << bfs() << '\n';
  return 0;
}