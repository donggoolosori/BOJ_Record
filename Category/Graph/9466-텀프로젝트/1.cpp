#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define MAX 100000

using namespace std;

int next_node[MAX + 1], visit[MAX + 1], finished[MAX + 1];
int order, grouped;

void dfs(int curr) {
  visit[curr] = order++;

  if (visit[next_node[curr]] == 0) {
    dfs(next_node[curr]);
  } else if (!finished[next_node[curr]]) {
    grouped += visit[curr] - visit[next_node[curr]] + 1;
  }

  finished[curr] = true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    memset(visit, 0, sizeof(visit));
    memset(finished, 0, sizeof(finished));
    order = 0, grouped = 0;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> next_node[i];
    }

    for (int i = 1; i <= n; i++) {
      if (finished[i]) continue;

      dfs(i);
    }

    cout << n - grouped << '\n';
  }

  return 0;
}