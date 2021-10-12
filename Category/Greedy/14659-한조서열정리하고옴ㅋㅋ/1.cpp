#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  int heights[30000];
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  int maxKill = 0;

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = i + 1; j < n; j++) {
      if (heights[i] > heights[j])
        cnt++;
      else
        break;
    }
    if (cnt > maxKill) maxKill = cnt;
  }

  cout << maxKill;

  return 0;
}