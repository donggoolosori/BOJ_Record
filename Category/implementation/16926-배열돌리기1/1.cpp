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

int N, M, R;
int arr[300][300];

void rotate() {
  for (int sy = 0, sx = 0, ey = N - 1, ex = M - 1; sy < ey && sx < ex;
       sy++, sx++, ey--, ex--) {
    int next = arr[sy][sx];
    // left
    for (int r = sy + 1; r <= ey; r++) {
      swap(arr[r][sx], next);
    }
    // down
    for (int c = sx + 1; c <= ex; c++) {
      swap(arr[ey][c], next);
    }
    // right
    for (int r = ey - 1; r >= sy; r--) {
      swap(arr[r][ex], next);
    }
    // up
    for (int c = ex - 1; c >= sx; c--) {
      swap(arr[sy][c], next);
    }
  }
}

int main() {
  FAST_IO;

  cin >> N >> M >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < R; i++) {
    rotate();
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}