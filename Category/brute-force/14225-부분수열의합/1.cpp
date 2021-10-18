#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n, nums[20];
set<int> subSum;

void dfs(int idx, int sum) {
  if (idx == n) return;

  subSum.insert(sum + nums[idx]);
  dfs(idx + 1, sum);
  dfs(idx + 1, sum + nums[idx]);
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];
}

int main() {
  input();
  dfs(0, 0);

  int curr = -1;
  if (*subSum.begin() != 1) {
    cout << 1 << '\n';
    return 0;
  }
  for (auto iter = subSum.begin(); iter != subSum.end(); iter++) {
    if (curr == -1) {
      curr = *iter;
      continue;
    }
    if (curr + 1 < *iter) {
      cout << curr + 1 << '\n';
      return 0;
    }
    curr = *iter;
  }
  cout << curr + 1 << '\n';

  return 0;
}