// 플로이드 워셜 알고리즘은 음의 사이클이 존재할 경우 사용할 수 없다
#include <iostream>
#include <vector>

using namespace std;

int graph[501][501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T, N, M, W;
  cin >> T;
  while (T--) {
    cin >> N >> M >> W;
    // graph 초기화
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j)
          graph[i][j] = 0;
        else
          graph[i][j] = 2e9;
      }
    }

    int fr, to, c;
    while (M--) {
      cin >> fr >> to >> c;
      if (graph[fr][to] > c) graph[fr][to] = c;
      if (graph[to][fr] > c) graph[to][fr] = c;
    }
    while (W--) {
      cin >> fr >> to >> c;
      graph[fr][to] = -c;
    }

    for (int k = 1; k <= N; k++) {
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }
    bool flag = false;
    for (int i = 1; i <= N; i++) {
      if (graph[i][i] < 0) {
        flag = true;
        break;
      }
    }
    cout << (flag ? "YES" : "NO") << '\n';
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        cout << graph[i][j] << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}