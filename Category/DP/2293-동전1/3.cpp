#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int coins[100] = {0}, cache[100001] = {0};
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> coins[i];

  cache[0] = 1;
  for (int i = 0; i < n; i++) {
    int coin = coins[i];
    for (int j = coin; j <= k; j++) cache[j] += cache[j - coin];
  }
  cout << cache[k];
  return 0;
}