#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int N, K, learned[26], answer;
vector<set<int>> needAlps;

int getNumOfKnowingWords() {
  int ret = 0;

  for (const auto &st : needAlps) {
    bool flag = true;
    for (const auto &alp : st) {
      if (!learned[alp]) {
        flag = false;
        break;
      }
    }
    if (flag) ret++;
  }

  return ret;
}

void dfs(int L, int start) {
  if (L == K) {
    // for (int i = 0; i < 26; i++) cout << learned[i] << ' ';
    // cout << '\n';
    answer = max(answer, getNumOfKnowingWords());
    return;
  }
  for (int i = start; i < 26; i++) {
    if (learned[i]) continue;
    learned[i] = true;
    dfs(L + 1, i + 1);
    learned[i] = false;
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
    set<int> st;
    for (int j = 4; j <= s.length() - 5; j++) st.insert(s[j] - 'a');
    needAlps.push_back(st);
  }

  // anta, tica를 배우려면 최소 5개 학습 가능해야함
  if (K < 5) {
    cout << 0;
    return 0;
  }
  // anta, tica 필수 학습
  K -= 5;
  vector<char> shouldKnow = {'a', 't', 'n', 'c', 'i'};
  for (const auto &el : shouldKnow) learned[el - 'a'] = true;

  dfs(0, 0);

  cout << answer;

  return 0;
}