#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ans;
int n;

bool isPrime(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}

void dfs(int L, int num) {
  if (L == 0) {
    dfs(L + 1, 2);
    dfs(L + 1, 3);
    dfs(L + 1, 5);
    dfs(L + 1, 7);
    return;
  }
  if (L == n) {
    ans.push_back(num);
    return;
  }

  for (int i = 1; i <= 9; i++) {
    int next_num = num * 10 + i;
    if (!isPrime(next_num)) continue;
    dfs(L + 1, next_num);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  dfs(0, 0);
  for (const auto &el : ans) {
    cout << el << '\n';
  }
  return 0;
}