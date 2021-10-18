#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, s;
int nums[20];
int cnt = 0;

void dfs(int idx, int sum) {
  if (idx == n) {
    return;
  }
  if (sum + nums[idx] == s) {
    cnt++;
  }

  dfs(idx + 1, sum + nums[idx]);
  dfs(idx + 1, sum);
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> nums[i];
}

int main() {
  input();

  dfs(0, 0);
  cout << cnt << '\n';

  return 0;
}