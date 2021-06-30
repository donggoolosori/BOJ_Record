#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int idx, cost;
  bool operator<(const Node &b) const { return cost > b.cost; }
};
vector<Node> graph[100001];
int visit[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int answer = 0;

  int V, E;
  cin >> V >> E;

  int a, b, c;
  while (E--) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  visit[1] = true;
  priority_queue<Node> pq;
  for (const auto &el : graph[1]) {
    pq.push(el);
  }

  int maxRoad = 0;
  while (!pq.empty()) {
    int idx = pq.top().idx, cost = pq.top().cost;
    pq.pop();

    if (visit[idx]) continue;
    visit[idx] = true;
    maxRoad = max(maxRoad, cost);
    answer += cost;

    for (const auto &next : graph[idx]) {
      if (visit[next.idx]) continue;
      pq.push(next);
    }
  }
  answer -= maxRoad;
  cout << answer << '\n';

  return 0;
}