#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long
#define MAX 8

using namespace std;

struct Pos {
  int y, x;
};
int dy[] = {0, 0, -1, 1, 1, 1, -1, -1}, dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
unordered_map<string, int> dir;

int main() {
  FAST_IO;

  dir["R"] = 0;
  dir["L"] = 1;
  dir["B"] = 2;
  dir["T"] = 3;
  dir["RT"] = 4;
  dir["LT"] = 5;
  dir["RB"] = 6;
  dir["LB"] = 7;

  int n;
  string k, s;

  cin >> k >> s >> n;

  Pos king, stone;

  king.x = k[0] - 'A', king.y = k[1] - '0' - 1;
  stone.x = s[0] - 'A', stone.y = s[1] - '0' - 1;

  for (int i = 0; i < n; i++) {
    string next;
    cin >> next;

    int d = dir[next];

    int kny = king.y + dy[d], knx = king.x + dx[d];
    int sny = stone.y, snx = stone.x;

    if (kny < 0 || knx < 0 || kny >= MAX || knx >= MAX) continue;

    if (kny == stone.y && knx == stone.x) {
      sny += dy[d], snx += dx[d];
    }

    if (sny < 0 || snx < 0 || sny >= MAX || snx >= MAX) continue;

    king.y = kny, king.x = knx;
    stone.y = sny, stone.x = snx;
  }
  char kingCol = king.x + 'A', stoneCol = stone.x + 'A';

  cout << kingCol << king.y + 1 << '\n' << stoneCol << stone.y + 1 << '\n';

  return 0;
}