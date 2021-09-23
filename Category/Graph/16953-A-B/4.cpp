#include <iostream>
#include <queue>
#define ll long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll A, B;
  cin >> A >> B;

  queue<pair<ll, int>> q;
  q.push({A, 1});

  while (!q.empty()) {
    ll curr = q.front().first, cnt = q.front().second;
    q.pop();

    if (curr > B) continue;
    if (curr == B) {
      cout << cnt;
      return 0;
    }
    q.push({curr * 2, cnt + 1});
    q.push({curr * 10 + 1, cnt + 1});
  }
  cout << -1;

  return 0;
}