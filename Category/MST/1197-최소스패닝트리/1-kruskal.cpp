#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int a, b, cost;
};
vector<Edge> edges;
int parent[10001];

bool compare(Edge a, Edge b) { return a.cost < b.cost; }

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a > b) swap(a, b);
  parent[b] = a;
}

bool compareParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  return a == b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int answer = 0;

  int V, E;
  cin >> V >> E;

  for (int i = 1; i <= V; i++) {
    parent[i] = i;
  }

  int a, b, c;
  while (E--) {
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }
  sort(edges.begin(), edges.end(), compare);

  for (const auto &edge : edges) {
    int v1 = edge.a, v2 = edge.b, cost = edge.cost;
    if (compareParent(v1, v2)) continue;
    unionParent(v1, v2);
    answer += cost;
  }
  cout << answer << '\n';

  return 0;
}