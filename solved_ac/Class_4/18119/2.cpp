#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> words(N);
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (const auto &c : s) {
      words[i] |= 1 << (c - 'a');
    }
  }

  int bit = 0x3ffffff;

  int o;
  char x;
  while (M--) {
    cin >> o >> x;
    // 잊음
    if (o == 1) {
      bit &= ~(1 << (x - 'a'));
    }
    // 기억
    else {
      bit |= (1 << (x - 'a'));
    }
    int cnt = 0;
    for (const auto &word : words) {
      if ((bit & word) == word) {
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}