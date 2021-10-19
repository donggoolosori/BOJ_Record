#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, marbles[10], ans;
bool deleted[10];

bool isFirstOrLast(int idx) {
  bool isFirst = true;
  for (int i = idx - 1; i >= 0; i--) {
    if (!deleted[i]) isFirst = false;
  }
  bool isLast = true;
  for (int i = idx + 1; i < n; i++) {
    if (!deleted[i]) isLast = false;
  }
  return isFirst || isLast;
}

int getEnergy(int idx) {
  int left, right;
  for (int i = idx - 1; i >= 0; i--) {
    if (!deleted[i]) {
      left = marbles[i];
      break;
    }
  }
  for (int i = idx + 1; i < n; i++) {
    if (!deleted[i]) {
      right = marbles[i];
      break;
    }
  }
  return left * right;
}

void dfs(int energy, int L) {
  if (L == n - 2) {
    if (energy > ans) ans = energy;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (deleted[i] || isFirstOrLast(i)) continue;
    deleted[i] = true;
    dfs(energy + getEnergy(i), L + 1);
    deleted[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> marbles[i];
  }
  dfs(0, 0);
  cout << ans << '\n';

  return 0;
}