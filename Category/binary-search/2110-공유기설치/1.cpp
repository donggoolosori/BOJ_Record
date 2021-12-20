#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define FOR(i, s, e) for (int i = s; i < e; i++)
#define INF 987654321
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MAX 200000

using namespace std;

int n, c, house[MAX];

int main() {
  FAST_IO;

  cin >> n >> c;
  FOR(i, 0, n) { cin >> house[i]; }

  sort(house, house + n);

  int low = 0, high = house[n - 1];

  while (low <= high) {
    int cnt = 1;

    int pre_i = 0;
    int mid = (low + high) / 2;

    for (int i = 1; i < n; i++) {
      if (house[i] - house[pre_i] >= mid) {
        pre_i = i;
        cnt++;
      }
    }

    if (cnt >= c) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << high;

  return 0;
}