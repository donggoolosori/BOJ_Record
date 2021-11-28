#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cache[2001][2001];

bool isPalindrome(vector<int> &sequence, int s, int e) {
  if (s == e) return true;
  if (s + 1 == e && sequence[s] == sequence[e]) return true;

  int &ret = cache[s][e];

  if (ret != -1) {
    return ret;
  }

  return ret =
             sequence[s] == sequence[e] && isPalindrome(sequence, s + 1, e - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(cache, -1, sizeof(cache));

  int n;
  cin >> n;

  vector<int> sequence(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> sequence[i];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;

    cout << isPalindrome(sequence, s, e) << '\n';
  }
  return 0;
}