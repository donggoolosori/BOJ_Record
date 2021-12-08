#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define FOR(i, s, e) for (int i = s; i < e; i++)
#define INF 987654321
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)

using namespace std;

int N, M, memory[101], cost[101], dp[101][10001];

int main() {
  FAST_IO;

  cin >> N >> M;
  FOR(i, 1, N + 1) { cin >> memory[i]; }
  FOR(i, 1, N + 1) { cin >> cost[i]; }

  int ans = INF;

  FOR(i, 1, N + 1) {
    FOR(j, 1, 10001) {
      if (cost[i] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], memory[i] + dp[i - 1][j - cost[i]]);
      }

      if (dp[i][j] >= M) ans = min(ans, j);
    }
  }

  cout << ans << '\n';

  return 0;
}