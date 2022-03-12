#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

using namespace std;

struct Edge {
  int fr, to, time;
};
int N, M;
vector<Edge> edges;
ll times[501];
const int INF = 2e9;

int bf(int s) {
  for (int i = 2; i <= N; i++) times[i] = INF;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      int fr = edges[j].fr, to = edges[j].to, time = edges[j].time;
      if (times[fr] == INF) continue;

      if (times[to] > times[fr] + time) {
        times[to] = times[fr] + time;

        if (i == N) {
          return true;
        }
      }
    }
  }

  return false;
}

int main() {
  FAST_IO;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  if (bf(1)) {
    cout << -1 << '\n';
  } else {
    for (int i = 2; i <= N; i++) {
      if (times[i] == INF) {
        cout << -1 << '\n';
      } else {
        cout << times[i] << '\n';
      }
    }
  }

  return 0;
}