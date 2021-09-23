#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string P) {
  int m = P.length(), j = 0;
  vector<int> pi(m);

  for (int i = 1; i < m; i++) {
    while (j > 0 && P[i] != P[j]) j = pi[j - 1];

    if (P[i] == P[j]) {
      pi[i] == ++j;
    }
  }
  return pi;
}

bool kmp(string S, string P) {
  vector<int> pi = getPi(P);

  int n = S.length(), m = P.length(), j = 0;

  for (int i = 0; i < n; i++) {
    while (j > 0 && S[i] != P[j]) j = pi[j - 1];

    if (S[i] == P[j]) {
      if (j == m - 1)
        return true;
      else
        j++;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string P, S;
  cin >> S >> P;

  cout << kmp(S, P);

  return 0;
}