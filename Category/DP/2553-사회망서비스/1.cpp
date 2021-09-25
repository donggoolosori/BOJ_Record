#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define MAX 1000000

using namespace std;

vector<int> graph[MAX + 1], tree[MAX + 1];
bool visit[MAX + 1];
int cache[MAX + 1][2];
int n;

void make_tree(int curr) {
  visit[curr] = true;
  for (const auto &next : graph[curr]) {
    if (visit[next]) continue;
    tree[curr].push_back(next);
    make_tree(next);
  }
}

void getInput() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
}

int dfs(int curr, int state) {
  int &ret = cache[curr][state];
  if (ret != -1) return ret;

  if (state == 1) {
    ret = 1;
    for (const auto &next : tree[curr]) {
      ret += min(dfs(next, 0), dfs(next, 1));
    }
  } else {
    ret = 0;
    for (const auto &next : tree[curr]) {
      ret += dfs(next, 1);
    }
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(cache, -1, sizeof(cache));
  getInput();
  make_tree(1);
  int ans = min(dfs(1, 0), dfs(1, 1));
  cout << ans << '\n';

  return 0;
}