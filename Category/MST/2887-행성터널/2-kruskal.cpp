#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

#define INF 987654321
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MAX 100000
#define PII pair<int, int>
#define TIII tuple<int, int, int>
using namespace std;

PII pos[3][MAX];
vector<TIII> edges;
int parent[MAX];
int n;

int getParent(int x) {
  if (x == parent[x]) return x;

  return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  // cycle 발생
  if (a == b) return false;

  if (a > b) swap(a, b);

  parent[b] = a;

  return true;
}

int compareParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  return a == b;
}

int kruskal() {
  int ret = 0;

  for (const auto &edge : edges) {
    int cost, a, b;
    tie(cost, a, b) = edge;

    if (!unionParent(a, b)) {
      continue;
    }

    ret += cost;
  }

  return ret;
}

int main() {
  FAST_IO;

  // 입력받기
  cin >> n;
  int v;
  for (int i = 0; i < n; i++) {
    for (int r = 0; r < 3; r++) {
      cin >> v;
      pos[r][i] = {v, i};
    }
  }

  // parent 초기화
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  // 간선 초기화
  for (int i = 0; i < 3; i++) {
    sort(pos[i], pos[i] + n);

    for (int j = 0; j < n - 1; j++) {
      int fr = pos[i][j].second, to = pos[i][j + 1].second;
      int cost = abs(pos[i][j].first - pos[i][j + 1].first);

      edges.push_back({cost, fr, to});
    }
  }

  sort(edges.begin(), edges.end());

  cout << kruskal();

  return 0;
}