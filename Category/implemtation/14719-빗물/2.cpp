#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int h, w, answer = 0;
  cin >> h >> w;
  vector<int> heights(w), lMaxs(w), rMaxs(w);
  for (int i = 0; i < w; i++) {
    cin >> heights[i];
  }
  int lMax = 0, rMax = 0;
  for (int l = 0, r = w - 1; l < w && r >= 0; l++, r--) {
    lMax = max(lMax, heights[l]);
    rMax = max(rMax, heights[r]);
    lMaxs[l] = lMax;
    rMaxs[r] = rMax;
  }

  for (int i = 1; i < w - 1; i++) {
    int bound = min(lMaxs[i - 1], rMaxs[i + 1]);
    answer += heights[i] >= bound ? 0 : bound - heights[i];
  }
  cout << answer;

  return 0;
}