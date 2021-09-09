// 2021-9-9
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxRes = -2e9, minRes = 2e9;

int calculate(int opIdx, int a, int b) {
  switch (opIdx) {
    case 0:
      return a + b;
    case 1:
      return a - b;
    case 2:
      return a * b;
    case 3:
      return a / b;
    default:
      return 0;
  }
}

void dfs(vector<int> &op, vector<int> &nums, int curr, int L) {
  if (L >= nums.size() - 1) {
    maxRes = max(maxRes, curr);
    minRes = min(minRes, curr);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (op[i] == 0) continue;
    op[i]--;
    dfs(op, nums, calculate(i, curr, nums[L + 1]), L + 1);
    op[i]++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> nums(N);
  vector<int> op(4);
  for (int i = 0; i < N; i++) cin >> nums[i];
  for (int i = 0; i < 4; i++) cin >> op[i];

  dfs(op, nums, nums[0], 0);

  cout << maxRes << '\n' << minRes << '\n';

  return 0;
}