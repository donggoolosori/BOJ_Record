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

int N, K;
struct Medal {
  int c, g, s, b;
};
Medal medals[1000];
Medal KInfo;

bool compare(Medal &a, Medal &b) {
  if (a.g == b.g) {
    if (a.s == b.s) {
      return a.b > b.b;
    }
    return a.s > b.s;
  }
  return a.g > b.g;
}

int main() {
  FAST_IO;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int c, g, s, b;
    cin >> c >> g >> s >> b;

    medals[i] = {c, g, s, b};

    if (c == K) {
      KInfo = {c, g, s, b};
    }
  }

  int rank = 1;

  for (int i = 0; i < N; i++) {
    if (compare(medals[i], KInfo)) {
      rank++;
    }
  }
  cout << rank << '\n';

  return 0;
}