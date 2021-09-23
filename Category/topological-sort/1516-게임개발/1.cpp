#include <iostream>
#include <queue>
#include <vector>
#define MAX 500
#define INF 100000
using namespace std;

vector<int> graph[MAX + 1];
int inDegree[MAX + 1], build_time[MAX + 1], minTime[MAX + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> build_time[i];
    while (true) {
      int x;
      cin >> x;
      if (x == -1) break;
      graph[x].push_back(i);
      inDegree[i]++;
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
      minTime[i] = build_time[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    int curr = q.front();
    q.pop();

    for (const auto &next : graph[curr]) {
      if (--inDegree[next] == 0) q.push(next);
      minTime[next] = max(minTime[next], minTime[curr] + build_time[next]);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << minTime[i] << '\n';
  }

  return 0;
}