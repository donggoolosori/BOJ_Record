// 4ms
#include <iostream>
#include <queue>

using namespace std;

int S;
struct Node {
  int emoj, op, clipboard;
};
bool visit[2001][2001];

int bfs() {
  queue<Node> q;
  q.push({1, 0, 0});
  visit[1][0] = true;

  while (!q.empty()) {
    int emoj = q.front().emoj, op = q.front().op,
        clipboard = q.front().clipboard;
    q.pop();

    if (emoj == S) return op;

    // copy
    q.push({emoj, op + 1, emoj});
    // paste
    if (emoj + clipboard < 2000 && !visit[emoj + clipboard][clipboard] &&
        clipboard > 0) {
      visit[emoj + clipboard][clipboard] = true;
      q.push({emoj + clipboard, op + 1, clipboard});
    }
    // delete
    if (emoj > 1 && !visit[emoj - 1][clipboard]) {
      visit[emoj - 1][clipboard] = true;
      q.push({emoj - 1, op + 1, clipboard});
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;
  cout << bfs();
  return 0;
}