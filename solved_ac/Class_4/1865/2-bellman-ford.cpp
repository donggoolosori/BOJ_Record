// bellman ford
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int fr, to, cost;
};
int N, dist[501];

bool bf(vector<Edge> &edges) {
  dist[1] = 0;

  for (int i = 1; i <= N; i++) {
    for (const auto &edge : edges) {
      int fr = edge.fr, to = edge.to, cost = edge.cost;

      if (dist[to] > cost + dist[fr]) {
        dist[to] = cost + dist[fr];

        if (i == N) return true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T, M, W;
  cin >> T;
  while (T--) {
    cin >> N >> M >> W;

    for (int i = 1; i <= N; i++) dist[i] = 1e9;
    vector<Edge> edges;

    int fr, to, c;
    while (M--) {
      cin >> fr >> to >> c;
      edges.push_back({fr, to, c});
      edges.push_back({to, fr, c});
    }
    while (W--) {
      cin >> fr >> to >> c;
      edges.push_back({fr, to, -c});
    }

    bool negative_cycle = bf(edges);
    if (negative_cycle)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }

  return 0;
}