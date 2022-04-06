#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int n;
int nums[11], selected[10];
int ops[4];
int maxRes = -2e9, minRes = 2e9;

void dfs(int L, int res) {
  if (L == n - 1) {
    maxRes = max(maxRes, res);
    minRes = min(minRes, res);
    return;
  }

  if (ops[0] > 0) {
    ops[0]--;
    dfs(L + 1, res + nums[L + 1]);
    ops[0]++;
  }
  if (ops[1] > 0) {
    ops[1]--;
    dfs(L + 1, res - nums[L + 1]);
    ops[1]++;
  }
  if (ops[2] > 0) {
    ops[2]--;
    dfs(L + 1, res * nums[L + 1]);
    ops[2]++;
  }
  if (ops[3] > 0) {
    ops[3]--;
    dfs(L + 1, res / nums[L + 1]);
    ops[3]++;
  }
}

int main() {
  FAST_IO;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  for (int i = 0; i < 4; i++) {
    cin >> ops[i];
  }

  dfs(0, nums[0]);

  cout << maxRes << '\n' << minRes << '\n';

  return 0;
}