#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int A, B;

int bfs() {
  queue<pair<int, int>> q;
  q.push({B, 1});

  while (!q.empty()) {
    int curr = q.front().first, dist = q.front().second;
    q.pop();

    if (curr < A) continue;
    if (curr == A) return dist;

    if (curr % 10 == 1) q.push({curr / 10, dist + 1});
    if (curr % 2 == 0) q.push({curr / 2, dist + 1});
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;
  cout << bfs();

  return 0;
}