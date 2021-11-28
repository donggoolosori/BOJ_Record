#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s1, s2;
  cin >> s1 >> s2;

  int len1 = s1.length(), len2 = s2.length();

  vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  int i = len1, j = len2;
  string lcs = "";

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      lcs = s1[i - 1] + lcs;
      i--, j--;

    } else {
      if (dp[i - 1][j] >= dp[i][j - 1]) {
        i--;
      } else {
        j--;
      }
    }
  }

  cout << dp[len1][len2] << '\n' << lcs << '\n';

  return 0;
}