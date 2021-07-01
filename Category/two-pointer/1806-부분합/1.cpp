#include <algorithm>
#include <iostream>
#define MAX 100000
using namespace std;

int N, S;
int arr[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> arr[i];

  int low = 0, high = 0, sum = 0, minLen = MAX;
  while (low <= high) {
    if (sum >= S) {
      minLen = min(minLen, high - low);
      sum -= arr[low++];
    } else {
      if (high == N) break;
      sum += arr[high++];
    }
  }
  if (minLen == MAX)
    cout << 0 << '\n';
  else
    cout << minLen << '\n';

  return 0;
}