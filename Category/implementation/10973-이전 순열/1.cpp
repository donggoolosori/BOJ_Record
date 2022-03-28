#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int arr[10000];

int main() {
  FAST_IO;

  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  bool flag = false;

  do {
    if (!flag) {
      flag = true;
      continue;
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << ' ';
    }
    return 0;
  } while (prev_permutation(arr.begin(), arr.end()));

  cout << -1 << '\n';

  return 0;
}