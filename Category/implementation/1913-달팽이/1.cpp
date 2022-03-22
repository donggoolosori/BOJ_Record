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

int N, target, arr[1000][1000], dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};

int main() {
  FAST_IO;

  cin >> N >> target;

  int y = 0, x = 0, ty, tx, d = 0;

  for (int i = N * N; i >= 1; i--) {
    arr[y][x] = i;

    if (i == target) {
      ty = y, tx = x;
    }

    int ny = y + dy[d], nx = x + dx[d];

    if (ny >= N || nx >= N || ny < 0 || nx < 0 || arr[ny][nx] != 0) {
      d = (d + 1) % 4;
      ny = y + dy[d], nx = x + dx[d];
    }

    y = ny, x = nx;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

  cout << ty + 1 << ' ' << tx + 1 << '\n';

  return 0;
}