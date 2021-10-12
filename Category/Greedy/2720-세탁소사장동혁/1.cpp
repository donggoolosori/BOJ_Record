#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int coins[4] = {25, 10, 5, 1};

  int T;
  cin >> T;
  while (T--) {
    int change;
    cin >> change;

    for (int i = 0; i < 4; i++) {
      int cnt = change / coins[i];
      cout << cnt << ' ';
      change %= coins[i];
    }
    cout << '\n';
  }

  return 0;
}