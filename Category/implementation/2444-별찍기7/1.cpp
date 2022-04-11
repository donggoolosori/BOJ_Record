#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printRow(int n, int idx) {
  int end = 2 * n - 1, mid = end / 2;
  for (int i = 0; i < mid + idx; i++) {
    if (i >= mid - idx + 1 && i <= mid + idx - 1)
      cout << '*';
    else
      cout << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    printRow(n, i);
  }
  for (int i = n - 1; i >= 1; i--) {
    printRow(n, i);
  }

  return 0;
}