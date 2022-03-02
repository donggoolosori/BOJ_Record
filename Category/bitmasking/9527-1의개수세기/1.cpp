#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define INF 987654321
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define ll long long
#define MAX 55

using namespace std;

ll A, B;
ll d[MAX];

ll getNumOf1(ll x) {
  ll ret = x & 1;

  for (int i = MAX - 1; i > 0; i--) {
    if (x & (1LL << i)) {
      ret += d[i - 1] + x - (1LL << i) + 1;
      x -= (1LL << i);
    }
  }

  return ret;
}

int main() {
  FAST_IO;

  cin >> A >> B;
  d[0] = 1;

  for (int i = 1; i < MAX; i++) {
    d[i] = d[i - 1] * 2 + (1LL << i);
  }

  ll ans = getNumOf1(B) - getNumOf1(A - 1);

  cout << ans << '\n';

  return 0;
}