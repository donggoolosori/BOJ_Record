#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int N, M, K;
struct Node {
  ll cost;
  int node, k;
  bool operator<(const Node& a) const { return cost > a.cost; }
};
vector<PII> graph[10001];
ll minCost[10001][21];
const ll INF = 1e11;

ll dijkstra() {
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      minCost[i][j] = INF;
    }
  }
  priority_queue<Node> pq;
  pq.push({0, 1, 0});
  minCost[1][0] = 0;

  while (!pq.empty()) {
    ll cost = pq.top().cost;
    int node = pq.top().node;
    int k = pq.top().k;
    pq.pop();

    if (cost > minCost[node][k]) continue;

    for (const auto& next : graph[node]) {
      int nextNode = next.second;
      ll nextCost = cost;

      if (k < K && minCost[nextNode][k + 1] > nextCost) {
        minCost[nextNode][k + 1] = nextCost;
        pq.push({nextCost, nextNode, k + 1});
      }

      nextCost += next.first;

      if (minCost[nextNode][k] > nextCost) {
        minCost[nextNode][k] = nextCost;
        pq.push({nextCost, nextNode, k});
      }
    }
  }

  ll ret = INF;
  for (int i = 0; i <= K; i++) {
    ret = min(ret, minCost[N][i]);
  }
  return ret;
}

int main() {
  FAST_IO;

  cin >> N >> M >> K;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }

  cout << dijkstra() << '\n';

  return 0;
}