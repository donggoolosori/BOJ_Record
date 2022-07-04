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

int E, S, M;

int main() {
  FAST_IO;

  cin >> E >> S >> M;

  int year = 1, e = 1, s = 1, m = 1;

  while (true) {
    if (e == E && s == S && m == M) {
      cout << year << '\n';
      return 0;
    }
    year++, e++, s++, m++;
    if (e > 15) e = 1;
    if (s > 28) s = 1;
    if (m > 19) m = 1;
  }

  return 0;
}