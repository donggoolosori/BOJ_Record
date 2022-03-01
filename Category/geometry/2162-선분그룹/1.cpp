#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define INF 987654321
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MAX 3000
#define pii pair<int, int>
#define ll long long

using namespace std;

int parent[MAX], n;
pii lines[MAX][2];

ll ccw(pii p1, pii p2, pii p3) {
  int x1, y1, x2, y2, x3, y3;
  tie(x1, y1) = p1;
  tie(x2, y2) = p2;
  tie(x3, y3) = p3;

  return x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
}

bool checkCross(int line1, int line2) {
  pii p1 = lines[line1][0], p2 = lines[line1][1], p3 = lines[line2][0],
      p4 = lines[line2][1];

  ll cond1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  ll cond2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  if (cond1 == 0 && cond2 == 0) {
    if (p1 > p2) swap(p1, p2);
    if (p3 > p4) swap(p3, p4);

    return p1 <= p4 && p3 <= p2;
  }

  return cond1 <= 0 && cond2 <= 0;
}

int getParent(int x) {
  if (x == parent[x]) return x;

  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a > b) swap(a, b);

  parent[b] = a;
}

int main() {
  FAST_IO;

  cin >> n;

  for (int i = 0; i < n; i++) {
    pii fr, to;
    cin >> fr.first >> fr.second >> to.first >> to.second;
    lines[i][0] = fr;
    lines[i][1] = to;

    parent[i] = i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!checkCross(i, j)) continue;

      unionParent(i, j);
    }
  }

  int numOfGroup = 0, maxSizeOfGroup = 0;
  unordered_map<int, int> groupCounter;

  for (int i = 0; i < n; i++) {
    int groupNum = getParent(i);

    if (i == groupNum) numOfGroup++;

    groupCounter[groupNum]++;

    maxSizeOfGroup = max(maxSizeOfGroup, groupCounter[groupNum]);
  }

  cout << numOfGroup << '\n' << maxSizeOfGroup << '\n';

  return 0;
}