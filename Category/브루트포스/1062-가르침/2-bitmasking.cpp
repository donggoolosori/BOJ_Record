#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K, answer, learned_bit;
vector<int> bits;

int getNumOfKnowingWords() {
  int ret = 0;

  for (const auto &bit : bits) {
    if ((learned_bit & bit) == bit) ret++;
  }

  return ret;
}

void dfs(int L, int start) {
  if (L == K) {
    answer = max(answer, getNumOfKnowingWords());
    return;
  }
  for (int i = start; i < 26; i++) {
    if (learned_bit & (1 << i)) continue;
    learned_bit |= (1 << i);
    dfs(L + 1, i + 1);
    learned_bit &= ~(1 << i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    int bit = 0;
    for (int j = 4; j <= s.length() - 5; j++) bit |= 1 << (s[j] - 'a');
    bits.push_back(bit);
  }

  // anta, tica를 배우려면 최소 5개 학습 가능해야함
  if (K < 5) {
    cout << 0;
    return 0;
  }
  // anta, tica 필수 학습
  K -= 5;
  vector<char> shouldKnow = {'a', 't', 'n', 'c', 'i'};
  for (const auto &el : shouldKnow) learned_bit |= 1 << (el - 'a');

  dfs(0, 0);

  cout << answer;

  return 0;
}