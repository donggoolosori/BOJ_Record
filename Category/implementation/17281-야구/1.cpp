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

int N;
int result[51][10];

int getScore(vector<int> &players) {
  int out = 0, playerIdx = 0, score = 0;

  for (int inning = 1; inning <= N; inning++) {
    vector<int> base = {0, 0, 0, 0};
    out = 0;

    while (out < 3) {
      int player = players[playerIdx];
      playerIdx = (playerIdx + 1) % 9;

      int res = result[inning][player];

      if (res == 0) {
        out++;
        continue;
      }

      for (int i = 3; i >= 1; i--) {
        if (base[i] == 0) continue;

        if (i + res >= 4) {
          score += 1;
          base[i] = 0;
        } else {
          swap(base[i + res], base[i]);
        }
      }

      if (res == 4) {
        score += 1;
      } else {
        base[res] = 1;
      }
    }
  }

  return score;
}

int main() {
  FAST_IO;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 9; j++) {
      cin >> result[i][j];
    }
  }

  vector<int> order = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int ans = 0;

  do {
    if (order[3] != 1) continue;

    ans = max(ans, getScore(order));
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << '\n';

  return 0;
}