#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001

using namespace std;

vector<int> graph[MAX];
int inDegree[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  priority_queue<int, vector<int>, greater<int>> pq;
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    inDegree[b]++;
  }

  for (int i = 1; i <= n; i++) {
    if (inDegree[i] == 0) pq.push(i);
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int curr = pq.top();
    pq.pop();
    ans.push_back(curr);

    for (const auto &next : graph[curr]) {
      if (--inDegree[next] == 0) pq.push(next);
    }
  }

  for (const auto &el : ans) cout << el << ' ';

  return 0;
}