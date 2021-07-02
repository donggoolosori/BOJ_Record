#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int n, k;
bool visit[MAX];

int bfs() {
  queue<pair<int, int>> q;
  q.push({n, 0});
  visit[n] = true;
  int minTime = 1e9;

  while (!q.empty()) {
    int curr = q.front().first, time = q.front().second;
    q.pop();
    visit[curr] = true;

    if (time > minTime) continue;
    if (curr == k) {
      minTime = min(minTime, time);
      continue;
    }

    if (curr < k && curr * 2 < MAX && !visit[curr * 2])
      q.push({curr * 2, time});
    if (curr < k && !visit[curr + 1]) q.push({curr + 1, time + 1});
    if (curr > 1 && !visit[curr - 1]) q.push({curr - 1, time + 1});
  }
  return minTime;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  if (n >= k) {
    cout << n - k;
    return 0;
  }
  cout << bfs();

  return 0;
}