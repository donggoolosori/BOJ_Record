#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
struct Node {
  int idx, cost;
  bool operator<(const Node &b) const { return cost > b.cost; }
};
vector<Node> graph[1001];
int dist[1001];

inline int dijkstra(int s, int e) {
  dist[s] = 0;
  priority_queue<Node> pq;
  pq.push({s, 0});

  while (!pq.empty()) {
    int curr = pq.top().idx, cost = pq.top().cost;
    pq.pop();

    if (dist[curr] > cost) continue;
    for (const auto &next : graph[curr]) {
      if (dist[next.idx] > cost + next.cost) {
        dist[next.idx] = cost + next.cost;
        pq.push({next.idx, dist[next.idx]});
      }
    }
  }

  return dist[e];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  int a, b, c;
  while (M--) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }
  int s, e;
  cin >> s >> e;

  // initialize dist
  for (int i = 1; i <= N; i++) dist[i] = 1e9;
  // do dijkstra
  int ans = dijkstra(s, e);
  cout << ans;

  return 0;
}