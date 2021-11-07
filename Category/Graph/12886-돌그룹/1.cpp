#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int a, b, c, total;
bool visit[501][501];

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c;
  total = a + b + c;
}

bool bfs() {
  if ((total) % 3 != 0) {
    return false;
  }

  queue<pair<int, int>> q;
  q.push({a, b});
  visit[a][b] = true;

  while (!q.empty()) {
    int cur_a = q.front().first, cur_b = q.front().second,
        cur_c = total - cur_a - cur_b;
    q.pop();

    if (cur_a == cur_b && cur_b == cur_c) {
      return true;
    }

    int select1[3] = {cur_a, cur_a, cur_b}, select2[3] = {cur_b, cur_c, cur_c};

    for (int i = 0; i < 3; i++) {
      int s1 = select1[i], s2 = select2[i];

      if (s1 < s2) {
        s2 -= s1;
        s1 *= 2;
      } else if (s2 < s1) {
        s1 -= s2;
        s2 *= 2;
      } else {
        continue;
      }

      int s3 = total - s2 - s1;

      int na = min(min(s1, s2), s3);
      int nb = max(max(s1, s2), s3);
      if (!visit[na][nb]) {
        visit[na][nb] = true;
        q.push({na, nb});
      }
    }
  }
  return false;
}

int main() {
  input();

  cout << bfs() << '\n';

  return 0;
}