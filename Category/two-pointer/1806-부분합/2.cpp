#include <algorithm>
#include <iostream>
#define MAX 100001

using namespace std;

int arr[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int low = 0, high = 0, sum = arr[0];
  int answer = MAX;

  while (high < n) {
    if (s > sum) {
      sum += arr[++high];
    } else {
      answer = min(answer, high - low + 1);
      sum -= arr[low++];
    }
  }

  cout << ((answer == MAX) ? 0 : answer) << '\n';

  return 0;
}