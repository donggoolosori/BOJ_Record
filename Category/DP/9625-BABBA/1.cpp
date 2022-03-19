#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int K, A, B;
PII dp[46];

int main() {
  FAST_IO;

  cin >> K;

  dp[0] = {1, 0};
  dp[1] = {0, 1};

  for (int i = 2; i <= K; i++) {
    dp[i].first = dp[i - 1].first + dp[i - 2].first;
    dp[i].second = dp[i - 1].second + dp[i - 2].second;
  }

  cout << dp[K].first << ' ' << dp[K].second << '\n';

  return 0;
}