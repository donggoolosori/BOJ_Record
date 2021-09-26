#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX 1000

using namespace std;

int n, m;
const int INF = 2e9;
struct Node {
  int idx, dist;
  bool operator<(const Node &b) const { return dist > b.dist; }
};
vector<Node> graph[MAX + 1];
int dp[MAX + 1];

void getInput() {
  cin >> n >> m;
  int a, b, c;
  while (m--) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
}

vector<int> dijkstra(int start) {
  priority_queue<Node> pq;
  pq.push({start, 0});
  vector<int> cache(n + 1, INF);
  cache[start] = 0;

  while (!pq.empty()) {
    int curr = pq.top().idx, dist = pq.top().dist;
    pq.pop();
    if (dist > cache[curr]) continue;

    for (const auto &item : graph[curr]) {
      int next_dist = dist + item.dist, next = item.idx;
      if (next_dist < cache[next]) {
        cache[next] = next_dist;
        pq.push({next, next_dist});
      }
    }
  }
  return cache;
}

int dfs(vector<int> &fromTwo, int curr) {
  if (curr == 2) return 1;

  int &ret = dp[curr];
  if (ret != -1) return ret;

  ret = 0;
  int dist = fromTwo[curr];
  for (const auto &item : graph[curr]) {
    int next = item.idx;
    int next_dist = fromTwo[next];
    if (dist <= next_dist) continue;
    ret += dfs(fromTwo, next);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));
  getInput();
  vector<int> fromTwo = dijkstra(2);
  cout << dfs(fromTwo, 1) << '\n';

  return 0;
}