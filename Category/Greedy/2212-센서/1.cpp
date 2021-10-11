#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> sensors(n);

  for (int i = 0; i < n; i++) {
    cin >> sensors[i];
  }

  if (n <= k) {
    cout << 0 << '\n';
    return 0;
  }

  sort(sensors.begin(), sensors.end());

  vector<int> dists;
  for (int i = 0; i < n - 1; i++) {
    dists.push_back(sensors[i + 1] - sensors[i]);
  }

  sort(dists.begin(), dists.end());

  int ans = 0;
  for (int i = 0; i < n - k; i++) {
    ans += dists[i];
  }
  cout << ans << '\n';

  return 0;
}