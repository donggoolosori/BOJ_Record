#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int k;

int main() {
  FAST_IO;

  cin >> k;
  deque<PII> dq(6);

  for (int i = 0; i < 6; i++) {
    cin >> dq[i].first >> dq[i].second;
  }

  while (!(dq[0].first == dq[2].first && dq[1].first == dq[3].first)) {
    dq.push_back(dq.front());
    dq.pop_front();
  }

  int ans = k * (dq[0].second * dq[1].second + dq[3].second * dq[4].second);
  cout << ans;
  return 0;
}