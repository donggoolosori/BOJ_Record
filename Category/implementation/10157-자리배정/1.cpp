#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long
#define MAX 1000

using namespace std;

int C, R, K;
bool visit[MAX + 1][MAX + 1];
int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};

int main() {
  FAST_IO;

  cin >> C >> R >> K;

  if (K > C * R) {
    cout << 0 << '\n';
    return 0;
  }

  int d = 0, y = 1, x = 1;

  for (int i = 1; i <= C * R; i++) {
    visit[y][x] = true;

    if (i == K) {
      cout << x << ' ' << y << '\n';
      break;
    }

    int ny = y + dy[d], nx = x + dx[d];

    if (ny <= 0 || nx <= 0 || ny > R || nx > C || visit[ny][nx]) {
      d = (d + 1) % 4;

      ny = y + dy[d], nx = x + dx[d];
    }
    y = ny, x = nx;
  }

  return 0;
}