#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

using namespace std;

struct Edge {
  int sy, sx, ey, ex, time;
};
vector<Edge> edges;
int N, M, G, E;
int map[30][30];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
ll times[30][30];
const int INF = 2e9;
int tombCnt = 0;

void initEdges() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] != 0) continue;
      if (i == N - 1 && j == M - 1) continue;

      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k], nx = j + dx[k];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (map[ny][nx] == 1) continue;

        edges.push_back({i, j, ny, nx, 1});
      }
    }
  }
}

int bf() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      times[i][j] = INF;
    }
  }
  times[0][0] = 0;

  const int v = N * M - tombCnt;

  for (int i = 1; i <= v; i++) {
    for (const auto &edge : edges) {
      int sy = edge.sy, sx = edge.sx, ey = edge.ey, ex = edge.ex,
          time = edge.time;

      if (times[sy][sx] == INF) continue;

      if (times[ey][ex] > times[sy][sx] + time) {
        times[ey][ex] = times[sy][sx] + time;

        if (i == v) {
          return true;
        }
      }
    }
  }

  return false;
}

int main() {
  FAST_IO;

  while (true) {
    edges.clear();
    memset(map, 0, sizeof(map));
    memset(times, 0, sizeof(times));
    tombCnt = 0;

    cin >> M >> N;

    if (M == 0 && N == 0) break;

    cin >> G;
    for (int i = 0; i < G; i++) {
      int x, y;
      cin >> x >> y;
      map[y][x] = 1;
      tombCnt++;
    }

    cin >> E;
    for (int i = 0; i < E; i++) {
      int sy, sx, ey, ex, time;
      cin >> sx >> sy >> ex >> ey >> time;
      edges.push_back({sy, sx, ey, ex, time});
      map[sy][sx] = -1;
    }

    initEdges();

    if (bf()) {
      cout << "Never" << '\n';
    } else {
      if (times[N - 1][M - 1] == INF) {
        cout << "Impossible" << '\n';
      } else {
        cout << times[N - 1][M - 1] << '\n';
      }
    }
  }

  return 0;
}