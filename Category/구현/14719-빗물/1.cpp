#include <iostream>

using namespace std;

int height[500];
int l_max[500], r_max[500];
int w, h;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> h >> w;
  for (int i = 0; i < w; i++) cin >> height[i];

  int l = 0, r = 0;
  for (int i = 0; i < w; i++) {
    l = max(l, height[i]);
    l_max[i] = l;
    r = max(r, height[w - i - 1]);
    r_max[w - i - 1] = r;
  }

  int answer = 0;
  for (int i = 1; i < w - 1; i++) {
    int curr = height[i], l_wall = l_max[i - 1], r_wall = r_max[i + 1];
    if (l_wall <= curr || r_wall <= curr) continue;
    answer += min(l_wall, r_wall) - curr;
  }
  cout << answer;

  return 0;
}