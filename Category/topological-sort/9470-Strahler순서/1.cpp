#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int k, m, p;
    cin >> k >> m >> p;
    vector<int> graph[m + 1], inDegree(m + 1);
    vector<pair<int, int>> maxStrahlers(m + 1, {0, 0});

    while (p--) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      inDegree[b]++;
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= m; i++) {
      if (inDegree[i] == 0) q.push({i, 1});
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
      if (q.empty()) return 0;

      int curr = q.front().first, strahler = q.front().second;
      ans = max(ans, strahler);
      q.pop();

      for (const auto &next : graph[curr]) {
        if (strahler > maxStrahlers[next].first) {
          maxStrahlers[next].first = strahler;
          maxStrahlers[next].second = 1;
        } else if (strahler == maxStrahlers[next].first) {
          maxStrahlers[next].second++;
        }

        if (--inDegree[next] == 0) {
          if (maxStrahlers[next].second >= 2) {
            q.push({next, maxStrahlers[next].first + 1});
          } else {
            q.push({next, maxStrahlers[next].first});
          }
        }
      }
    }
    cout << k << ' ' << ans << '\n';
  }

  return 0;
}