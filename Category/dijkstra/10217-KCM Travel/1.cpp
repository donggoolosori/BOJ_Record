#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>

using namespace std;

int N, M, K;
struct Node {
  int node, cost, time;
  bool operator<(const Node &a) const {
    if (time == a.time) {
      return cost > a.cost;
    };
    return time > a.time;
  }
};
int dp[101][10001];
vector<vector<Node>> graph;
const int INF = 2e9;

int dijkstra() {
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j] = INF;
    }
  }

  priority_queue<Node> pq;
  pq.push({1, 0, 0});
  dp[1][0] = 0;

  while (!pq.empty()) {
    Node curr = pq.top();
    pq.pop();

    int node = curr.node, cost = curr.cost, time = curr.time;

    if (dp[node][cost] < time) continue;

    for (const auto &next : graph[node]) {
      int nextTime = time + next.time;
      int nextCost = cost + next.cost;

      if (nextCost > M) continue;
      if (nextTime >= dp[next.node][nextCost]) continue;

      for (int i = nextCost + 1; i <= M; i++) {
        if (dp[next.node][i] <= nextTime) break;
        dp[next.node][i] = nextTime;
      }

      dp[next.node][nextCost] = nextTime;
      pq.push({next.node, nextCost, nextTime});
    }
  }

  int ret = INF;
  for (int i = 0; i <= M; i++) {
    if (ret <= dp[N][i]) continue;

    ret = dp[N][i];
  }

  return ret;
}

int main() {
  FAST_IO;

  int T;
  cin >> T;

  while (T--) {
    cin >> N >> M >> K;

    graph.clear();
    graph.resize(N + 1);

    for (int i = 0; i < K; i++) {
      int u, v, c, d;
      cin >> u >> v >> c >> d;
      graph[u].push_back({v, c, d});
    }

    int ans = dijkstra();

    if (ans == INF) {
      cout << "Poor KCM" << '\n';
    } else {
      cout << ans << '\n';
    }
  }

  return 0;
}