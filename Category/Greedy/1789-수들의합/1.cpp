#include <iostream>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll s;
  cin >> s;

  ll sum = 0, n;
  for (n = 1;; n++) {
    sum += n;
    if (s - sum <= n) break;
  }
  cout << n;

  return 0;
}