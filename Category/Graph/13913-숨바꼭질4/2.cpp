#include <iostream>
#include <queue>
#include <vector>
#define MAX 100000
using namespace std;

struct Node {
  int idx, time;
  vector<int> path;
};

bool visit[MAX + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  if (n >= k) {
    cout << n - k << '\n';
    for (int i = n; i >= k; i--) cout << i << ' ';
    return 0;
  }

  queue<Node> q;
  q.push({n, 0, {n}});
  int minTime = MAX;
  while (!q.empty()) {
    int curr = q.front().idx, time = q.front().time;
    vector<int> path = q.front().path;
    visit[curr] = true;
    q.pop();

    if (time > minTime) continue;
    if (curr == k) {
      cout << time << '\n';
      for (const auto &el : path) cout << el << ' ';
      return 0;
    }

    if (curr < k && curr * 2 <= MAX && !visit[curr * 2]) {
      path.push_back(curr * 2);
      q.push({curr * 2, time + 1, path});
      path.pop_back();
    }
    if (curr + 1 <= k && !visit[curr + 1]) {
      path.push_back(curr + 1);
      q.push({curr + 1, time + 1, path});
      path.pop_back();
    }
    if (curr - 1 > 0 && !visit[curr - 1]) {
      path.push_back(curr - 1);
      q.push({curr - 1, time + 1, path});
      path.pop_back();
    }
  }

  return 0;
}