#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define INF 987654321
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MAX 100000

using namespace std;

int positions[MAX], dp[MAX][5][5], power[5][5];
int n;

void setPower() {
  for (int s = 0; s <= 4; s++) {
    for (int e = 1; e <= 4; e++) {
      if (s == 0) {
        power[s][e] = 2;
      } else if (abs(e - s) == 2) {
        power[s][e] = 4;
      } else if (s == e) {
        power[s][e] = 1;
      } else {
        power[s][e] = 3;
      }
    }
  }
}

int getMinPower(int idx, int l, int r) {
  if (idx == n) {
    return 0;
  }

  int &ret = dp[idx][l][r];

  if (ret != -1) return ret;

  ret = INF;
  int next = positions[idx];

  if (next != r) {
    ret = min(ret, getMinPower(idx + 1, next, r) + power[l][next]);
  }
  if (next != l) {
    ret = min(ret, getMinPower(idx + 1, l, next) + power[r][next]);
  }

  return ret;
}

int main() {
  FAST_IO;

  for (int i = 0;; i++) {
    cin >> positions[i];
    if (positions[i] == 0) {
      n = i;
      break;
    }
  }

  setPower();

  memset(dp, -1, sizeof(dp));

  cout << getMinPower(0, 0, 0);

  return 0;
}