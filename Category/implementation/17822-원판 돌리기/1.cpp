#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long
#define MAX 50

using namespace std;

int N, M, T, sums[MAX + 1], counts[MAX + 1];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
deque<int> circles[MAX + 1];

void print() {
  cout << "------------\n";
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      cout << circles[i][j] << ' ';
    }
    cout << '\n';
  }
}

void rotate(int x, int d, int k) {
  for (int i = x; i <= N; i += x) {
    for (int j = 0; j < k; j++) {
      if (d == 0) {
        circles[i].push_front(circles[i].back());
        circles[i].pop_back();
      } else if (d == 1) {
        circles[i].push_back(circles[i].front());
        circles[i].pop_front();
      }
    }
  }
}

void erase() {
  bool flag = false;

  vector<PII> dels;

  for (int i = 1; i <= N; i++) {
    if (sums[i] == 0) continue;

    for (int j = 0; j < M; j++) {
      if (circles[i][j] == 0) continue;

      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k], nx = j + dx[k];
        if (ny > N || ny < 1) continue;

        if (nx == -1) {
          nx = M - 1;
        } else if (nx == M) {
          nx = 0;
        }

        if (circles[i][j] == circles[ny][nx]) {
          dels.push_back({i, j});
          dels.push_back({ny, nx});
        }
      }
    }
  }

  if (!dels.empty()) {
    for (const auto &del : dels) {
      int y = del.first, x = del.second;

      if (circles[y][x] == 0) continue;

      sums[y] -= circles[y][x];
      counts[y]--;

      circles[y][x] = 0;
    }
  } else {
    int sum = 0, count = 0;

    for (int i = 1; i <= N; i++) {
      sum += sums[i];
      count += counts[i];
    }

    float avg = (float)sum / count;

    for (int i = 1; i <= N; i++) {
      for (int j = 0; j < M; j++) {
        if (circles[i][j] == 0) continue;

        if (circles[i][j] > avg) {
          circles[i][j]--;
          sums[i]--;
        } else if (circles[i][j] < avg) {
          circles[i][j]++;
          sums[i]++;
        }
      }
    }
  }
}

int getSum() {
  int ret = 0;
  for (int i = 1; i <= N; i++) {
    ret += sums[i];
  }
  return ret;
}

int main() {
  FAST_IO;

  cin >> N >> M >> T;

  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 0; j < M; j++) {
      int v;
      cin >> v;
      sum += v;
      circles[i].push_back(v);

      counts[i]++;
    }
    sums[i] = sum;
  }

  for (int i = 0; i < T; i++) {
    int x, d, k;
    cin >> x >> d >> k;
    rotate(x, d, k);
    erase();
  }

  cout << getSum() << '\n';
  return 0;
}