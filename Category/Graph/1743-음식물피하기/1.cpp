#include <algorithm>
#include <iostream>

using namespace std;

int N, M, K;
bool trash[101][101], visit[101][101];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int dfs(int y, int x) {
  int ret = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
    if (visit[ny][nx] || trash[ny][nx] != true) continue;
    visit[ny][nx] = true;
    ret += dfs(ny, nx);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  int r, c;
  while (K--) {
    cin >> r >> c;
    trash[r][c] = true;
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (visit[i][j] || !trash[i][j]) continue;
      visit[i][j] = true;
      ans = max(ans, dfs(i, j));
    }
  }
  cout << ans;

  return 0;
}