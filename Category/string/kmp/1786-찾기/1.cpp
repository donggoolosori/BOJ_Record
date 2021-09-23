#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string p) {
  int m = p.size(), j = 0;
  vector<int> pi(m);

  for (int i = 1; i < m; i++) {
    while (j > 0 && p[i] != p[j]) j = pi[j - 1];
    if (p[i] == p[j]) pi[i] = ++j;
  }
  return pi;
}

vector<int> kmp(string t, string p) {
  vector<int> pi = getPi(p), ret;
  int n = t.size(), m = p.size(), j = 0;

  for (int i = 0; i < n; i++) {
    while (j > 0 && t[i] != p[j]) j = pi[j - 1];
    if (t[i] == p[j]) {
      if (j == m - 1) {
        ret.push_back(i - m + 2);
        j = pi[j];
      } else
        j++;
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string t, p;
  getline(cin, t);
  getline(cin, p);
  vector<int> ans = kmp(t, p);

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';

  return 0;
}