#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int fr, to, cost;
};

int N, M;
int parent[100001];
vector<Edge> edges;

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

bool sameParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  return a == b;
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

  sort(edges.begin(), edges.end(), compare);

  for (int i = 1; i <= N; i++) parent[i] = i;

  int answer = 0, maxCost = 0;
  for (const auto &edge : edges) {
    int fr = edge.fr, to = edge.to, cost = edge.cost;
    if (fr == to || sameParent(fr, to)) continue;
    maxCost = max(maxCost, cost);
    answer += cost;
    unionParent(fr, to);
  }
  answer -= maxCost;
  cout << answer << '\n';

  return 0;
}