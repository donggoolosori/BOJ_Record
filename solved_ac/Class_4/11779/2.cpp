#include <iostream>
#include <queue>

using namespace std;

int n, m;
struct Node {
  int idx, cost;
  bool operator<(const Node &b) const { return cost > b.cost; }
};
vector<Node> graph[1001];
int dist[1001];
int path[1001];
int s, e;

void dijkstra() {
  for (int i = 1; i <= n; i++) {
    dist[i] = 2e9;
  }
  priority_queue<Node> pq;
  dist[s] = 0;
  pq.push({s, 0});

  while (!pq.empty()) {
    Node curr = pq.top();
    pq.pop();

    if (curr.cost > dist[curr.idx]) continue;

    for (const auto &next : graph[curr.idx]) {
      if (next.cost + curr.cost < dist[next.idx]) {
        path[next.idx] = curr.idx;
        dist[next.idx] = next.cost + curr.cost;
        pq.push({next.idx, dist[next.idx]});
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  int a, b, c;
  while (m--) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }
  cin >> s >> e;

  dijkstra();

  vector<int> result_path;
  cout << dist[e] << '\n';
  while (e) {
    result_path.push_back(e);
    e = path[e];
  }
  cout << result_path.size() << '\n';
  for (auto iter = result_path.rbegin(); iter != result_path.rend(); iter++) {
    cout << *iter << ' ';
  }

  return 0;
}