#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string words[10];
int n, m, maxNum, alpCoefficient[26];
bool check[10];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> words[i];
    string word = words[i];
    int len = word.length();
    int pow = 1;

    for (int j = len - 1; j >= 0; j--) {
      int alpIdx = word[j] - 'A';
      alpCoefficient[alpIdx] += pow;
      pow *= 10;
    }
  }

  sort(alpCoefficient, alpCoefficient + 26, greater<int>());

  int ans = 0;
  for (int i = 0, num = 9; i < 26 && num >= 0; i++, num--) {
    ans += alpCoefficient[i] * num;
  }
  cout << ans << '\n';

  return 0;
}