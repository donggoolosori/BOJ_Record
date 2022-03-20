#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long
#define MAX 100

using namespace std;

struct Edge {
  int fr, to, dist;
};
vector<Edge> edges;
int N, M, dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
int map[MAX + 1][MAX + 1];
bool visit[MAX + 1][MAX + 1];
queue<PII> corners;
int parent[7];
int countryNum = 1;

void setCountryNum(int y, int x, const int &num) {
  map[y][x] = num;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];

    if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
    if (map[ny][nx] == 0 || map[ny][nx] == num) continue;

    setCountryNum(ny, nx, num);
  }
}

void findCorners() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (map[i][j] != 0 || visit[i][j]) continue;

      queue<PII> q;
      q.push({i, j});
      visit[i][j] = true;

      while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
          int ny = y + dy[i], nx = x + dx[i];
          if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
          if (visit[ny][nx]) continue;
          visit[ny][nx] = true;
          if (map[ny][nx] != 0) {
            corners.push({ny, nx});
            continue;
          }
          q.push({ny, nx});
        }
      }
    }
  }
}

void findEdges() {
  while (!corners.empty()) {
    int y = corners.front().first, x = corners.front().second;
    int country = map[y][x];
    corners.pop();

    // left
    for (int c = x - 1; c >= 1; c--) {
      if (map[y][c] == 0) continue;
      if (map[y][c] == country) break;
      int dist = x - c - 1;
      if (dist >= 2) {
        edges.push_back({country, map[y][c], dist});
      }

      break;
    }
    // right
    for (int c = x + 1; c <= M; c++) {
      if (map[y][c] == 0) continue;
      if (map[y][c] == country) break;
      int dist = c - x - 1;
      if (dist >= 2) {
        edges.push_back({country, map[y][c], dist});
      }

      break;
    }
    // top
    for (int r = y - 1; r >= 1; r--) {
      if (map[r][x] == 0) continue;
      if (map[r][x] == country) break;
      int dist = y - r - 1;
      if (dist >= 2) {
        edges.push_back({country, map[r][x], dist});
      }

      break;
    }
    // bottom
    for (int r = y + 1; r <= N; r++) {
      if (map[r][x] == 0) continue;
      if (map[r][x] == country) break;
      int dist = r - y - 1;
      if (dist >= 2) {
        edges.push_back({country, map[r][x], dist});
      }

      break;
    }
  }
}

bool compare(Edge &a, Edge &b) { return a.dist < b.dist; }

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  // cycle 발생시 false 리턴
  if (a == b) return false;

  if (a > b) swap(a, b);

  parent[b] = a;

  return true;
}

bool sameParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a == b) return true;
  return false;
}

int kruskal() {
  int ret = 0;

  sort(edges.begin(), edges.end(), compare);

  for (int i = 1; i <= 6; i++) parent[i] = i;

  for (const auto &edge : edges) {
    int a = edge.fr, b = edge.to, dist = edge.dist;

    if (!unionParent(a, b)) continue;

    ret += dist;
  }

  for (int i = 2; i < countryNum; i++) {
    if (!sameParent(1, i)) {
      return -1;
    }
  }

  return ret;
}

int main() {
  FAST_IO;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> map[i][j];
      if (map[i][j] == 1) map[i][j] = -1;
    }
  }

  // 섬마다 번호 부여
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (map[i][j] != -1) continue;

      setCountryNum(i, j, countryNum++);
    }
  }

  // 섬들의 가장 자리 위치 찾기
  findCorners();

  // 모든 섬 사이의 간선 찾기
  findEdges();

  // kruskal 알고리즘으로 MST 찾기
  cout << kruskal() << '\n';

  return 0;
}
