#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 2e9;
int n, m, fr, to;
struct Node {
  int idx, cost;
  bool operator<(const Node &b) const { return cost > b.cost; }
};
vector<Node> graph[1001];

int getMinCost() {
  priority_queue<Node> pq;
  pq.push({fr, 0});
  vector<int> d(n + 1, INF);
  d[fr] = 0;

  while (!pq.empty()) {
    int idx = pq.top().idx, cost = pq.top().cost;
    pq.pop();

    if (d[idx] < cost) continue;

    for (const auto &next : graph[idx]) {
      int n_idx = next.idx, n_cost = next.cost;
      if (d[n_idx] > cost + n_cost) {
        d[n_idx] = cost + n_cost;
        pq.push({n_idx, cost + n_cost});
      }
    }
  }

  return d[to];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }
  cin >> fr >> to;

  cout << getMinCost();

  return 0;
}