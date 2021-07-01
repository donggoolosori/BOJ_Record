#include <iostream>

using namespace std;

int n, m;
char war[100][100];
bool visit[100][100];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int dfs(int y, int x, char color) {
  int ret = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
    if (visit[ny][nx] || war[ny][nx] != color) continue;
    visit[ny][nx] = true;
    ret += dfs(ny, nx, color);
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> war[i][j];

  int white = 0, blue = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visit[i][j]) continue;
      visit[i][j] = true;
      if (war[i][j] == 'W') {
        int cnt = dfs(i, j, 'W');
        white += cnt * cnt;
      } else {
        int cnt = dfs(i, j, 'B');
        blue += cnt * cnt;
      }
    }
  }
  cout << white << ' ' << blue << '\n';

  return 0;
}