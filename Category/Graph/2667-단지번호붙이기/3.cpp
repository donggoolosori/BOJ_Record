// bfs
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;
char maps[25][25];
bool visit[25][25];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int bfs(int y, int x) {
  char target = maps[y][x];
  queue<pair<int, int>> q;
  visit[y][x] = true;
  q.push({y, x});
  int cnt = 0;

  while (!q.empty()) {
    int y = q.front().first, x = q.front().second;
    cnt++;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (visit[ny][nx]) continue;
      if (maps[ny][nx] != target) continue;

      visit[ny][nx] = true;
      q.push({ny, nx});
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maps[i][j];
    }
  }

  int cnt = 0;
  vector<int> i_cnt;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (maps[i][j] == '0' || visit[i][j]) continue;
      cnt++;
      i_cnt.push_back(bfs(i, j));
    }
  }
  sort(i_cnt.begin(), i_cnt.end());
  cout << cnt << '\n';
  for (const auto &el : i_cnt) cout << el << '\n';

  return 0;
}