#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

bool visit[MAX + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  if (n >= k) {
    cout << n - k;
    return 0;
  }

  queue<pair<int, int>> q;
  q.push({n, 0});
  int minTime = MAX;

  while (!q.empty()) {
    int curr = q.front().first, time = q.front().second;
    visit[curr] = true;
    q.pop();

    if (time > minTime) continue;
    if (curr == k) {
      minTime = time;
      continue;
    }

    if (curr < k && 2 * curr <= MAX && !visit[2 * curr]) {
      q.push({2 * curr, time});
    }
    if (curr + 1 <= k && !visit[curr + 1]) {
      q.push({curr + 1, time + 1});
    }
    if (curr - 1 > 0 && !visit[curr - 1]) {
      q.push({curr - 1, time + 1});
    }
  }
  cout << minTime;

  return 0;
}