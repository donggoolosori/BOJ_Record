#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int coins[100] = {0};
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> coins[i];
  vector<int> cache(k + 1, 1e9);

  cache[0] = 0;
  for (int i = 0; i < n; i++) {
    int coin = coins[i];
    for (int j = coin; j <= k; j++)
      cache[j] = min(cache[j], cache[j - coin] + 1);
  }
  int ans = cache[k] == 1e9 ? -1 : cache[k];
  cout << ans;
  return 0;
}