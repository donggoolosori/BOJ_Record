#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, r;
int answer;
int items[101];
int dist[101];
struct Node {
  int idx, cost;
  bool operator<(const Node &b) const { return cost > b.cost; }
};
vector<Node> graph[101];

void dijkstra(int start) {
  for (int i = 1; i <= n; i++) {
    dist[i] = 2e9;
  }
  priority_queue<Node> pq;
  dist[start] = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    Node curr = pq.top();
    pq.pop();

    if (dist[curr.idx] < curr.cost) continue;

    for (const auto &next : graph[curr.idx]) {
      if (dist[next.idx] > next.cost + curr.cost) {
        dist[next.idx] = next.cost + curr.cost;
        pq.push({next.idx, dist[next.idx]});
      }
    }
  }
}

int getItems() {
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] <= m) {
      ret += items[i];
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    cin >> items[i];
  }
  int a, b, c;
  while (r--) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  for (int start = 1; start <= n; start++) {
    dijkstra(start);
    answer = max(answer, getItems());
  }
  cout << answer;

  return 0;
}