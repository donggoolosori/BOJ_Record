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

using namespace std;

int visit[MAX];
PII pos[3][MAX];
vector<PII> costs[MAX];
int n;

int prim() {
  int ret = 0;

  priority_queue<PII, vector<PII>, greater<PII>> pq;
  // cost, idx
  pq.push({0, 0});

  while (!pq.empty()) {
    int cost, idx;
    tie(cost, idx) = pq.top();
    pq.pop();

    if (visit[idx]) continue;
    visit[idx] = true;
    ret += cost;

    for (const auto &next : costs[idx]) {
      if (visit[next.second]) continue;

      pq.push(next);
    }
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

  for (int i = 0; i < 3; i++) {
    sort(pos[i], pos[i] + n);
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n - 1; j++) {
      int fr = pos[i][j].second, to = pos[i][j + 1].second;
      int cost = abs(pos[i][j].first - pos[i][j + 1].first);
      costs[fr].push_back({cost, to});
      costs[to].push_back({cost, fr});
    }
  }

  cout << prim();

  return 0;
}