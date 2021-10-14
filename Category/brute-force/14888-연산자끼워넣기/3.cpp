#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, nums[100], op[4];
int maxNum = -2e9, minNum = 2e9;

void dfs(int L, int num) {
  if (L == n - 1) {
    if (maxNum < num) maxNum = num;
    if (minNum > num) minNum = num;
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (op[i] == 0) continue;
    op[i] -= 1;
    switch (i) {
      case 0:
        dfs(L + 1, num + nums[L + 1]);
        break;
      case 1:
        dfs(L + 1, num - nums[L + 1]);
        break;
      case 2:
        dfs(L + 1, num * nums[L + 1]);
        break;
      case 3:
        dfs(L + 1, num / nums[L + 1]);
        break;
      default:
        break;
    }
    op[i] += 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];
  for (int i = 0; i < 4; i++) cin >> op[i];

  dfs(0, nums[0]);

  cout << maxNum << '\n' << minNum << '\n';

  return 0;
}