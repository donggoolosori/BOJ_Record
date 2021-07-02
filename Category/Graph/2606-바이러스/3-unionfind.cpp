#include <iostream>

using namespace std;

int parent[101];

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

bool compareParent(int a, int b) { return getParent(a) == getParent(b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int v, e;
  cin >> v >> e;

  // initialize parent
  for (int i = 1; i <= v; i++) parent[i] = i;

  int a, b;
  while (e--) {
    cin >> a >> b;
    unionParent(a, b);
  }

  int cnt = 0;
  for (int i = 2; i <= v; i++) {
    if (compareParent(1, i)) cnt++;
  }
  cout << cnt;

  return 0;
}