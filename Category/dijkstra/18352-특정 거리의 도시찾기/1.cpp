#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>

using namespace std;

int N, M, K, X;
vector<int> graph[300001];
int dist[300001];
const int INF = 2e9;

void djikstra() {
  for (int i = 1; i <= N; i++) {
    if (i == X) continue;
    dist[i] = INF;
  }

  priority_queue<PII, vector<PII>, greater<PII>> pq;
  pq.push({0, X});

  while (!pq.empty()) {
    int curr = pq.top().second, cost = pq.top().first;
    pq.pop();

    if (cost > dist[curr]) continue;

    for (const auto &next : graph[curr]) {
      if (dist[next] <= cost + 1) continue;

      dist[next] = cost + 1;
      pq.push({dist[next], next});
    }
  }
}

int main() {
  FAST_IO;

  cin >> N >> M >> K >> X;

  for (int i = 0; i < M; i++) {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
  }

  djikstra();

  bool flag = false;
  for (int i = 1; i <= N; i++) {
    if (dist[i] == K) {
      cout << i << '\n';
      flag = true;
    }
  }

  if (!flag) cout << -1 << '\n';

  return 0;
}