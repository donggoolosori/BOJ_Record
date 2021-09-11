// 2021-9-10
#include <algorithm>
#include <iostream>

using namespace std;

int n, k, answer;
int wordBits[50];

int getReadable(int bit) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((bit & wordBits[i]) == wordBits[i]) cnt++;
  }
  return cnt;
}

void dfs(int L, int start, int bit) {
  if (L == k) {
    answer = max(answer, getReadable(bit));
    return;
  }

  for (int i = start; i < 26; i++) {
    if (bit & (1 << i)) continue;
    dfs(L + 1, i + 1, bit | (1 << i));
  }
}

int convertWordToBit(string word) {
  int bit = 0;
  for (const auto &ch : word) {
    bit |= 1 << (ch - 'a');
  }

  return bit;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  string word;
  for (int i = 0; i < n; i++) {
    cin >> word;
    wordBits[i] = convertWordToBit(word);
  }

  if (k < 5) {
    cout << 0;
    return 0;
  }
  k -= 5;

  char basics[] = {'a', 't', 'c', 'n', 'i'};
  int bit = 0;
  for (const auto &alp : basics) {
    bit |= (1 << (alp - 'a'));
  }

  dfs(0, 0, bit);

  cout << answer;

  return 0;
}