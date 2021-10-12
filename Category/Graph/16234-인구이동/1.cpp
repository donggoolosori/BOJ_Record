#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N, L, R;
int land[50][50];
bool visit[50][50];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

bool canUnite(int myPopulation, int yourPopulation) {
  int diff = abs(myPopulation - yourPopulation);
  if (diff >= L && diff <= R) return true;
  return false;
}

bool bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  visit[y][x] = true;

  vector<pair<int, int>> unions;
  int unionCnt = 0, unionPopulation = 0;

  while (!q.empty()) {
    int cy = q.front().first, cx = q.front().second;
    unions.push_back({cy, cx});
    unionCnt++;
    unionPopulation += land[cy][cx];
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i], nx = cx + dx[i];
      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (visit[ny][nx] || !canUnite(land[cy][cx], land[ny][nx])) continue;

      visit[ny][nx] = true;
      q.push({ny, nx});
    }
  }

  if (unionCnt <= 1) return false;

  int newPopulation = unionPopulation / unionCnt;
  for (const auto &pos : unions) {
    land[pos.first][pos.second] = newPopulation;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> land[i][j];
    }
  }

  int day = 0;
  while (true) {
    bool flag = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (visit[i][j]) continue;
        if (bfs(i, j)) flag = true;
      }
    }
    if (!flag) break;
    memset(visit, 0, sizeof(visit));
    day++;
  }
  cout << day << '\n';

  return 0;
}