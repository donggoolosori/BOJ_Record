#include <iostream>
#include <vector>
#define ll long long

using namespace std;

struct Edge {
  int fr, to, cost;
};
const int INF = 2e9;
int N, M;
vector<Edge> edges;
ll dist[501];

bool bf() {
  for (int i = 2; i <= N; i++) {
    dist[i] = INF;
  }
  for (int i = 1; i <= N; i++) {
    for (const auto &edge : edges) {
      int fr = edge.fr, to = edge.to, cost = edge.cost;
      if (dist[fr] == INF) continue;
      if (dist[to] > dist[fr] + cost) {
        dist[to] = dist[fr] + cost;
        if (i == N) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  int a, b, c;
  while (M--) {
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  bool negative_cycle = bf();

  if (negative_cycle) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 2; i <= N; i++) {
    if (dist[i] == INF)
      cout << -1 << '\n';
    else
      cout << dist[i] << '\n';
  }

  return 0;
}