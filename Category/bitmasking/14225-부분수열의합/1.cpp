#include <iostream>
#include <string>
#include <vector>
#define MAX 100000 * 20

using namespace std;

int n;
int nums[20], check[MAX + 1];

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
}

int getMinImpossibleSum() {
  for (int i = 1; i < (1 << n); i++) {
    int sum = 0;
    for (int j = 0; j < 20; j++) {
      if (i & (1 << j)) {
        sum += nums[j];
      }
    }
    check[sum] = 1;
  }

  for (int i = 1; i <= MAX; i++) {
    if (!check[i]) {
      return i;
    }
  }
  return -1;
}

int main() {
  input();
  cout << getMinImpossibleSum() << '\n';

  return 0;
}