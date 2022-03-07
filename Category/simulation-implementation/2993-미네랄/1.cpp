#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100
#define pii pair<int, int>

using namespace std;

const int INF = 2e9;
int R, C, N;
char cave[MAX][MAX];
bool airCluster[MAX][MAX], visit[MAX][MAX];
int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};
vector<pii> airClusterList;

void printCave() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << cave[i][j];
    }
    cout << '\n';
  }
}

bool throwStick(int height, bool isLeft) {
  if (isLeft) {
    for (int i = 0; i < C; i++) {
      if (cave[height][i] == 'x') {
        cave[height][i] = '.';
        return true;
      }
    }
  } else {
    for (int i = C - 1; i >= 0; i--) {
      if (cave[height][i] == 'x') {
        cave[height][i] = '.';
        return true;
      }
    }
  }

  return false;
}

void bfs(int sy, int sx) {
  queue<pii> q;
  q.push({sy, sx});
  visit[sy][sx] = true;

  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
      if (visit[ny][nx] || cave[ny][nx] == '.') continue;

      visit[ny][nx] = true;
      q.push({ny, nx});
    }
  }
}

bool checkAirCluster() {
  memset(visit, false, sizeof(visit));
  memset(airCluster, 0, sizeof(airCluster));
  airClusterList.clear();

  for (int i = 0; i < C; i++) {
    if (cave[R - 1][i] != 'x' || visit[R - 1][i]) continue;

    bfs(R - 1, i);
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (cave[i][j] != 'x' || visit[i][j]) continue;

      airCluster[i][j] = true;
      airClusterList.push_back({i, j});
    }
  }

  return !airClusterList.empty();
}

void workGravity() {
  int fallDist = INF;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (cave[i][j] == '.' || visit[i][j]) continue;

      int dist = 0;
      for (int k = i + 1; k < R; k++) {
        if (cave[k][j] == 'x') {
          if (airCluster[k][j]) {
            dist = INF;
          }
          break;
        }
        dist++;
      }

      fallDist = min(fallDist, dist);
    }
  }

  sort(airClusterList.begin(), airClusterList.end(), greater<pii>());

  for (int i = 0; i < airClusterList.size(); i++) {
    int y, x;
    tie(y, x) = airClusterList[i];

    cave[y][x] = '.';
    cave[y + fallDist][x] = 'x';
  }
}

int main() {
  FAST_IO;

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> cave[i][j];
    }
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    int height;
    cin >> height;

    height = R - height;

    bool isLeft = true;
    if (i % 2 != 0) {
      isLeft = false;
    }

    if (!throwStick(height, isLeft)) {
      continue;
    }

    if (!checkAirCluster()) {
      continue;
    }

    workGravity();
  }

  printCave();

  return 0;
}