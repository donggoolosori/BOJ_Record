#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  int crane[50];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> crane[i];
  }
  sort(crane, crane + n, greater<int>());
  cin >> m;
  int boxes[10000];
  for (int j = 0; j < m; j++) {
    cin >> boxes[j];
  }
  sort(boxes, boxes + m, greater<int>());

  if (boxes[0] > crane[0]) {
    cout << -1 << '\n';
    return 0;
  }

  int cnt = 0, moveCnt = 0;
  while (moveCnt < m) {
    cnt++;
    int crane_idx = 0;
    for (int j = 0; j < m; j++) {
      if (boxes[j] == 0) continue;
      if (boxes[j] > crane[crane_idx]) continue;
      if (crane_idx == m) break;
      boxes[j] = 0;
      moveCnt++;
      crane_idx++;
    }
  }
  cout << cnt << '\n';

  return 0;
}