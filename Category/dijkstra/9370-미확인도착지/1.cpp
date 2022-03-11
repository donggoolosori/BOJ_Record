#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>

using namespace std;

int n, m, t, s, g, h;
int candidates[100];
int ghDist;
int dists[3][2001];
const int INF = 2e9;

void dijkstra(int sx, int row, vector<PII> *graph) {
  for (int i = 1; i <= n; i++) dists[row][i] = INF;

  priority_queue<PII> pq;
  pq.push({0, sx});
  dists[row][sx] = 0;

  while (!pq.empty()) {
    int dist, x;
    tie(dist, x) = pq.top();
    pq.pop();

    if (dist > dists[row][x]) continue;

    for (const auto &next : graph[x]) {
      int nx, nDist;
      tie(nDist, nx) = next;
      if (dists[row][nx] > dist + nDist) {
        dists[row][nx] = dist + nDist;
        pq.push({dists[row][nx], nx});
      }
    }
  }
}

int main() {
  FAST_IO;

  int T;
  cin >> T;

  while (T--) {
    cin >> n >> m >> t >> s >> g >> h;

    vector<PII> graph[2001];

    for (int i = 0; i < m; i++) {
      int a, b, d;
      cin >> a >> b >> d;
      graph[a].push_back({d, b});
      graph[b].push_back({d, a});

      if ((a == g && b == h) || (a == h && b == g)) {
        ghDist = d;
      }
    }

    for (int i = 0; i < t; i++) {
      cin >> candidates[i];
    }

    dijkstra(s, 0, graph);
    dijkstra(g, 1, graph);
    dijkstra(h, 2, graph);

    vector<int> ans;

    for (int i = 0; i < t; i++) {
      int e = candidates[i];

      if (dists[0][e] == dists[0][g] + ghDist + dists[2][e] ||
          dists[0][e] == dists[0][h] + ghDist + dists[1][e]) {
        ans.push_back(e);
      }
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}