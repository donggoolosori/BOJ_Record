#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int n, k;
bool visit[MAX];

void bfs() {
  int cnt = 0, minTime = MAX;
  queue<pair<int, int>> q;
  visit[n] = true;
  q.push({n, 0});

  while (!q.empty()) {
    int curr = q.front().first, time = q.front().second;
    q.pop();
    visit[curr] = true;

    if (time > minTime) continue;
    if (curr == k) {
      minTime = time;
      cnt++;
      continue;
    }

    if (curr < k && 2 * curr < MAX && !visit[curr * 2]) {
      q.push({curr * 2, time + 1});
    }
    if (curr < k && !visit[curr + 1]) {
      q.push({curr + 1, time + 1});
    }
    if (curr > 1 && !visit[curr - 1]) {
      q.push({curr - 1, time + 1});
    }
  }
  cout << minTime << '\n' << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  if (n >= k) {
    cout << n - k << '\n' << 1;
    return 0;
  }

  bfs();

  return 0;
}