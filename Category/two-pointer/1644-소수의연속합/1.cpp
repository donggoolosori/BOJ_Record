#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<int> primes;
bool isNotPrime[4000001];

void eratos() {
  isNotPrime[1] = true;

  for (int i = 2; i <= sqrt(n); i++) {
    if (isNotPrime[i]) continue;

    for (int j = i * 2; j <= n; j += i) {
      isNotPrime[j] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  eratos();

  for (int i = 1; i <= n; i++) {
    if (isNotPrime[i]) continue;
    primes.push_back(i);
  }

  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }

  int s = 0, e = 0, sum = primes[0], cnt = 0;
  while (e < primes.size()) {
    if (sum == n) cnt++;

    if (sum >= n) {
      sum -= primes[s++];
    } else {
      if (e + 1 >= primes.size()) break;
      sum += primes[++e];
    }
  }

  cout << cnt << '\n';

  return 0;
}