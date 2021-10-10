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

  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    pq.push(num);
    if (n == 1) {
      cout << 0;
      return 0;
    }
  }

  int ans = 0;
  while (!pq.empty()) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    ans += (a + b);
    if (pq.empty()) {
      break;
    }
    pq.push(a + b);
  }

  cout << ans << '\n';

  return 0;
}