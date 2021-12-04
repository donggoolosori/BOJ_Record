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
#define MAX 16

using namespace std;

int n;
int cost[MAX][MAX], dp[MAX][1 << 17];

int dfs(int curr, int bit) {
  bit |= (1 << curr);

  if (bit == ((1 << n) - 1)) {
    if (cost[curr][0] == 0) {
      return INF;
    }

    return cost[curr][0];
  }

  int &ret = dp[curr][bit];
  if (ret != -1) {
    return ret;
  }

  ret = INF;
  FOR(i, 0, n) {
    if (cost[curr][i] == 0) continue;
    if (bit & (1 << i)) continue;

    ret = min(ret, dfs(i, bit) + cost[curr][i]);
  }

  return ret;
}

int main() {
  FAST_IO;

  cin >> n;

  FOR(i, 0, n) {
    FOR(j, 0, n) { cin >> cost[i][j]; }
  }

  memset(dp, -1, sizeof(dp));

  cout << dfs(0, 0);

  return 0;
}