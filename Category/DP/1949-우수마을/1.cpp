#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define MAX 10000

using namespace std;

int n;
vector<int> graph[MAX + 1], tree[MAX + 1];
int head_count[MAX + 1], cache[MAX + 1][2];
bool visit[MAX + 1];

void make_tree(int curr) {
  visit[curr] = true;
  for (const auto &next : graph[curr]) {
    if (visit[next]) continue;
    tree[curr].push_back(next);
    make_tree(next);
  }
}

void get_input() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> head_count[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

int dfs(int curr, int state) {
  int &ret = cache[curr][state];
  if (ret != -1) return ret;

  if (state == 1) {
    ret = head_count[curr];
    for (const auto &next : tree[curr]) {
      ret += dfs(next, 0);
    }
  } else {
    ret = 0;
    for (const auto &next : tree[curr]) {
      ret += max(dfs(next, 1), dfs(next, 0));
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(cache, -1, sizeof(cache));
  get_input();
  make_tree(1);
  cout << max(dfs(1, 0), dfs(1, 1));

  return 0;
}