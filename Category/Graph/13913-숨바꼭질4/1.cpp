#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int n, k;
bool visit[MAX];
struct Node {
  int pos, time;
  vector<int> path;
};

void bfs() {
  queue<Node> q;
  q.push({n, 0, {n}});
  visit[n] = true;

  while (!q.empty()) {
    int curr = q.front().pos, time = q.front().time;
    vector<int> path = q.front().path;
    q.pop();

    visit[curr] = true;

    if (curr == k) {
      cout << time << '\n';
      for (const auto &el : path) {
        cout << el << ' ';
      }
      return;
    }

    if (curr < k && curr * 2 < MAX && !visit[curr * 2]) {
      path.push_back(curr * 2);
      q.push({curr * 2, time + 1, path});
      path.pop_back();
    }
    if (curr < k && !visit[curr + 1]) {
      path.push_back(curr + 1);
      q.push({curr + 1, time + 1, path});
      path.pop_back();
    }
    if (curr > 1 && !visit[curr - 1]) {
      path.push_back(curr - 1);
      q.push({curr - 1, time + 1, path});
      path.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  if (n >= k) {
    cout << n - k << '\n';
    for (int i = n; i >= k; i--) {
      cout << i << ' ';
    }
    return 0;
  }
  bfs();

  return 0;
}