#include <iostream>
#include <string>
#include <vector>
#define MAX 1000

using namespace std;

string map[MAX];
int visit[MAX][MAX], finished[MAX][MAX];
int n, m, cycle, order;

pair<int, int> getNextPos(int y, int x) {
  switch (map[y][x]) {
    case 'U':
      return {y - 1, x};
    case 'D':
      return {y + 1, x};
    case 'L':
      return {y, x - 1};
    case 'R':
      return {y, x + 1};
    default:
      return {y, x};
  }
}

void dfs(int y, int x) {
  visit[y][x] = order++;

  pair<int, int> nextPos = getNextPos(y, x);
  int ny = nextPos.first, nx = nextPos.second;

  if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
    if (visit[ny][nx] == 0) {
      dfs(ny, nx);
    } else if (!finished[ny][nx]) {
      cycle++;
    }
  }

  finished[y][x] = true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> map[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (finished[i][j]) continue;

      dfs(i, j);
    }
  }

  cout << cycle << '\n';

  return 0;
}