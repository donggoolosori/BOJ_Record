#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int N, M;
int graph[101][101];

void fw() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (graph[i][k] == 0) continue;

        if (graph[i][k] == graph[k][j]) {
          graph[i][j] = graph[i][k];
        }
      }
    }
  }
}

void print() {
  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      if (graph[i][j] == 0) cnt++;
    }
    cout << cnt << '\n';
  }
}

int main() {
  FAST_IO;

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int big, small;
    cin >> big >> small;
    graph[big][small] = 1;
    graph[small][big] = -1;
  }

  fw();
  print();

  return 0;
}