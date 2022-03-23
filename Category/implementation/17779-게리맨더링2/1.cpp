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

const int INF = 2e9;
int population[21][21], area[21][21];
int N;

void splitArea(int y, int x, int d1, int d2) {
  memset(area, 0, sizeof(area));

  for (int i = 0; i <= d1; i++) {
    area[y + i][x - i] = 5;
    area[y + d2 + i][x + d2 - i] = 5;
  }
  for (int i = 0; i <= d2; i++) {
    area[y + i][x + i] = 5;
    area[y + d1 + i][x - d1 + i] = 5;
  }

  for (int i = 1; i < y + d1; i++) {
    for (int j = 1; j <= x; j++) {
      if (area[i][j] == 5) break;
      area[i][j] = 1;
    }
  }
  for (int i = 1; i <= y + d2; i++) {
    for (int j = N; j >= x + 1; j--) {
      if (area[i][j] == 5) break;
      area[i][j] = 2;
    }
  }
  for (int i = y + d1; i <= N; i++) {
    for (int j = 1; j < x - d1 + d2; j++) {
      if (area[i][j] == 5) break;
      area[i][j] = 3;
    }
  }

  for (int i = y + d2 + 1; i <= N; i++) {
    for (int j = N; j >= x - d1 + d2; j--) {
      if (area[i][j] == 5) break;
      area[i][j] = 4;
    }
  }
}

int getMinDiff(int y, int x, int d1, int d2) {
  splitArea(y, x, d1, d2);

  vector<int> sum(6);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int areaNum = area[i][j];

      if (area[i][j] == 0) areaNum = 5;

      sum[areaNum] += population[i][j];
    }
  }

  sort(sum.begin(), sum.end());

  return sum[5] - sum[1];
}

int main() {
  FAST_IO;

  int ans = INF;

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> population[i][j];
    }
  }

  for (int i = 2; i <= N - 1; i++) {
    for (int j = 2; j <= N - 1; j++) {
      int y = i, x = j;

      for (int d1 = 1; j - d1 >= 1; d1++) {
        for (int d2 = 1; j + d2 <= N; d2++) {
          if (i + d1 + d2 > N) break;

          ans = min(ans, getMinDiff(i, j, d1, d2));
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}