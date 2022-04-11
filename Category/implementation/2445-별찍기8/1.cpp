#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printRow(int n, int idx) {
  for (int i = 0; i < 2 * n; i++) {
    if (i <= idx - 1 || i >= 2 * n - idx)
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