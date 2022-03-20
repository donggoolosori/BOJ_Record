#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long
#define N 5

using namespace std;

int arr[N];

int main() {
  FAST_IO;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = N - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        for (int k = 0; k < N; k++) {
          cout << arr[k] << ' ';
        }
        cout << '\n';
      }
    }
  }

  return 0;
}