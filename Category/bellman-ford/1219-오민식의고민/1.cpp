#include <iostream>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

struct Edge {
  int fr, to, cost;
};
const int INF = 2e9;
int N, M, s, e;
vector<Edge> edges;
bool adj[100][100], visit[100];
ll dist[100], income[100];
bool isGee[100];

bool isConnected(int curr) {
  if (curr == e) return true;
  visit[curr] = true;
  bool ret = false;
  for (int i = 0; i < N; i++) {
    if (curr == i) continue;
    if (visit[i] || !adj[curr][i]) continue;
    ret |= isConnected(i);
  }
  return ret;
}

void bf() {
  for (int i = 0; i < N; i++) dist[i] = -INF;
  dist[s] = income[s];

  for (int i = 1; i <= N; i++) {
    for (const auto &edge : edges) {
      int fr = edge.fr, to = edge.to, cost = edge.cost;
      if (dist[fr] == -INF) continue;
      if (dist[to] < dist[fr] + income[to] - cost) {
        dist[to] = dist[fr] + income[to] - cost;
        if (i == N) isGee[to] = true;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> s >> e >> M;
  int a, b, c;
  while (M--) {
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
    adj[a][b] = true;
  }
  for (int i = 0; i < N; i++) cin >> income[i];

  bf();

  if (dist[e] == -INF)
    cout << "gg";
  else {
    for (int i = 0; i < N; i++) {
      if (!isGee[i]) continue;
      if (isConnected(i)) {
        cout << "Gee";
        return 0;
      }
    }
    cout << dist[e];
  }

  return 0;
}