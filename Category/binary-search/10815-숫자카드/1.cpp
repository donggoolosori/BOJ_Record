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
#define MAX 500000

using namespace std;

int n, m, myCards[MAX], cards[MAX];

bool binarySearch(int target) {
  int s = 0, e = m - 1;

  while (s <= e) {
    int mid = (s + e) / 2;

    if (myCards[mid] == target) {
      return true;
    } else if (myCards[mid] > target) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return false;
}

int main() {
  FAST_IO;

  cin >> n;
  FOR(i, 0, n) { cin >> myCards[i]; }
  cin >> m;
  FOR(i, 0, m) { cin >> cards[i]; }

  sort(myCards, myCards + m);

  FOR(i, 0, m) {
    int card = cards[i];
    if (binarySearch(card)) {
      cout << 1 << ' ';
    } else {
      cout << 0 << ' ';
    }
  }

  return 0;
}