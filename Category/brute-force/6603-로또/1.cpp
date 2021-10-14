#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k, selected[13], nums[13];

void showCases(int L, int idx) {
  if (L == 6) {
    for (int i = 0; i < 6; i++) cout << selected[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = idx; i < k; i++) {
    selected[L] = nums[i];
    showCases(L + 1, i + 1);
  }
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> k;
    if (k == 0) return;

    for (int i = 0; i < k; i++) {
      cin >> nums[i];
    }
    showCases(0, 0);
    cout << '\n';
  }
}

int main() {
  input();
  return 0;
}