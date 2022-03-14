#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long
#define MAX 2501

using namespace std;

int N, M;
int prices[MAX];
ll dp[MAX][MAX];
vector<PII> graph[MAX];
struct Node {
  ll cost;
  int idx, minOil;

  bool operator<(const Node &a) const { return cost > a.cost; }
};
const ll INF = 1e12;

void input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> prices[i];
  }

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
}

ll dijkstra() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 2500; j++) {
      dp[i][j] = INF;
    }
  }
  priority_queue<Node> pq;
  pq.push({0, 1, prices[1]});
  dp[1][prices[1]] = 0;

  while (!pq.empty()) {
    Node curr = pq.top();
    ll cost = curr.cost;
    int idx = curr.idx, minOil = curr.minOil;
    pq.pop();

    if (cost > dp[idx][minOil]) continue;
    if (idx == N) return cost;

    for (const auto &next : graph[idx]) {
      int nextIdx = next.second;
      ll nextCost = cost + next.first * minOil;
      int nextOil = min(minOil, prices[nextIdx]);

      if (dp[nextIdx][minOil] <= nextCost) continue;

      dp[nextIdx][minOil] = nextCost;

      pq.push({nextCost, nextIdx, nextOil});
    }
  }

  return INF;
}

int main() {
  FAST_IO;

  input();

  ll ans = dijkstra();

  cout << ans << '\n';

  return 0;
}