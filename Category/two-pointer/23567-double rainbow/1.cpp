#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define INF 10001

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  unordered_map<int, int> inner, outer;

  int n, k;
  cin >> n >> k;

  vector<int> colors(n);
  set<int> inner_set, outer_set;

  for (int i = 0; i < n; i++) {
    cin >> colors[i];
    if (i == 0) {
      inner[colors[i]]++;
      inner_set.insert(colors[i]);
      continue;
    }
    outer[colors[i]]++;
    outer_set.insert(colors[i]);
  }

  int s = 0, e = 0;
  int answer = INF;
  while (e < n) {
    if (inner_set.size() < k) {
      e++;
      if (e >= n) break;

      if (--outer[colors[e]] == 0) {
        outer_set.erase(colors[e]);
      }
      inner_set.insert(colors[e]);
      inner[colors[e]]++;
    } else {
      if (--inner[colors[s]] == 0) {
        inner_set.erase(colors[s]);
      }
      outer_set.insert(colors[s]);
      outer[colors[s]]++;
      s++;
    }

    if (inner_set.size() == k && outer_set.size() == k) {
      answer = min(answer, e - s + 1);
    }
  }

  if (answer == INF)
    cout << 0 << '\n';
  else
    cout << answer << '\n';

  return 0;
}