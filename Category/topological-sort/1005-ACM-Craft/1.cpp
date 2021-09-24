#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int n, k, target;
    cin >> n >> k;
    vector<int> build_time(n + 1), graph[n + 1], inDegree(n + 1),
        complete_time(n + 1);
    // 건물 건설 시간
    for (int i = 1; i <= n; i++) cin >> build_time[i];
    // 빌드 순서
    while (k--) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      inDegree[b]++;
    }
    // 승리하기 위해 지어야 할 건물 번호
    cin >> target;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (inDegree[i] == 0) {
        q.push(i);
        complete_time[i] = build_time[i];
      }
    }
    for (int i = 1; i <= n; i++) {
      int curr = q.front();
      q.pop();

      for (const auto &next : graph[curr]) {
        complete_time[next] =
            max(complete_time[next], build_time[next] + complete_time[curr]);
        if (--inDegree[next] == 0) {
          q.push(next);
        }
      }
    }
    cout << complete_time[target] << '\n';
  }

  return 0;
}