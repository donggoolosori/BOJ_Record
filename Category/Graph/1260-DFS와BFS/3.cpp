#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
int graph[1001][1001];
bool visit[1001];

void dfs(int curr) {
  cout << curr << ' ';
  for (int next = 1; next <= n; next++) {
    if (visit[next] || !graph[curr][next]) continue;
    visit[next] = true;
    dfs(next);
  }
}

void bfs(int start) {
  visit[start] = true;
  queue<int> q;
  q.push(start);

  while (!q.empty()) {
    int curr = q.front();
    cout << curr << ' ';
    q.pop();

    for (int next = 1; next <= n; next++) {
      if (visit[next] || !graph[curr][next]) continue;
      visit[next] = true;
      q.push(next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> v;
  int a, b;
  while (m--) {
    cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  visit[v] = true;
  dfs(v);
  memset(visit, 0, sizeof(visit));
  cout << '\n';
  bfs(v);

  return 0;
}