#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string &P) {
  int len = P.length();
  vector<int> pi(len);

  for (int i = 1, j = 0; i < len; i++) {
    while (j > 0 && P[i] != P[j]) j = P[j - 1];
    if (P[i] == P[j]) pi[i] = ++j;
  }
  return pi;
}

void kmp(string &S, string &P) {
  vector<int> pi = getPi(P);
  int n = S.length(), m = P.length();

  for (int i = 0, j = 0; i < n; i++) {
    while (j > 0 && S[i] != P[j]) j = pi[j - 1];
    if (S[i] == P[j]) {
      if (j == m - 1) {
        cout << 1;
        return;
      }
      j++;
    }
  }
  cout << 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S, P;
  cin >> S;
  cin >> P;
  kmp(S, P);

  return 0;
}