#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int A, B;
struct Node {
  ll num, dist;
};

ll bfs() {
  queue<Node> q;
  q.push({A, 1});

  while (!q.empty()) {
    Node curr = q.front();
    q.pop();

    if (curr.num == B) {
      return curr.dist;
    }
    if (curr.num * 2 <= B) q.push({curr.num * 2, curr.dist + 1});
    if (curr.num * 10 + 1 <= B) q.push({curr.num * 10 + 1, curr.dist + 1});
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