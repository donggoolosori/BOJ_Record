#include <cstring>
#include <iostream>

using namespace std;

int N;
int maps[17][17];
int cache[17][17][3];
int dy[] = {0, 1, 1}, dx[] = {1, 0, 1};

// dir: 0 right, 1 down, 2 diag
int getCases(int y, int x, int dir) {
  if (y == N && x == N) return 1;
  int &ret = cache[y][x][dir];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = 0; i < 3; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny > N || nx > N) continue;
    if (maps[ny][nx] == 1) continue;
    if ((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;
    if (i == 2 && (maps[y + 1][x] == 1 || maps[y][x + 1] == 1)) continue;
    ret += getCases(ny, nx, i);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) cin >> maps[i][j];

  memset(cache, -1, sizeof(cache));
  cout << getCases(1, 2, 0);

  return 0;
}