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

int w, h;
char building[MAX + 2][MAX + 2];
bool visit[MAX + 2][MAX + 2];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
queue<PII> fireQ, sanguenQ;

// 불 번짐
void fire() {
  int fireSize = fireQ.size();

  while (fireSize--) {
    int y, x;
    tie(y, x) = fireQ.front();
    fireQ.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
      if (building[ny][nx] != '.') continue;
      building[ny][nx] = '*';

      fireQ.push({ny, nx});
    }
  }
}

// 탈출 이동
int escape() {
  int size = sanguenQ.size();

  if (size == 0) {
    return -1;
  }

  while (size--) {
    PII curr = sanguenQ.front();
    int y = curr.first, x = curr.second;
    sanguenQ.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= h || nx >= w) {
        return 1;
      }

      if (visit[ny][nx] || building[ny][nx] != '.') continue;

      visit[ny][nx] = true;

      sanguenQ.push({ny, nx});
    }
  }

  return 0;
}

int main() {
  FAST_IO;

  int T;
  cin >> T;

  while (T--) {
    memset(visit, false, sizeof(visit));
    while (!sanguenQ.empty()) sanguenQ.pop();
    while (!fireQ.empty()) fireQ.pop();

    cin >> w >> h;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> building[i][j];

        if (building[i][j] == '@') {
          sanguenQ.push({i, j});
          building[i][j] = '.';
          visit[i][j] = true;
        } else if (building[i][j] == '*') {
          fireQ.push({i, j});
        }
      }
    }

    int ans = 0;

    while (true) {
      ans++;

      fire();

      int status = escape();

      if (status == 1) {
        cout << ans << '\n';
        break;
      } else if (status == -1) {
        cout << "IMPOSSIBLE" << '\n';
        break;
      }
    }
  }

  return 0;
}