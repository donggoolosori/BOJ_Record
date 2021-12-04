#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define FOR(i, s, e) for (int i = s; i < e; i++)
#define MAX 500
#define INF 987654321

using namespace std;

int n;
int matrix[MAX][2], dp[MAX][MAX];

int dfs(int left, int right) {
  if (left == right) return 0;

  int &ret = dp[left][right];
  if (ret != -1) return ret;

  int minValue = INF;
  FOR(i, left, right) {
    minValue =
        min(minValue, dfs(left, i) + dfs(i + 1, right) +
                          matrix[left][0] * matrix[i][1] * matrix[right][1]);
  }

  return ret = minValue;
}

int main() {
  FAST_IO;

  cin >> n;

  FOR(i, 0, n) { cin >> matrix[i][0] >> matrix[i][1]; }

  memset(dp, -1, sizeof(dp));

  cout << dfs(0, n - 1) << '\n';

  return 0;
}