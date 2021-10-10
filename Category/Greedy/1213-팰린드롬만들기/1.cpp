#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numOfAlp[26];

bool canMakePalindrome(int len) {
  int oddCount = 0;
  for (int i = 0; i < 26; i++) {
    if (numOfAlp[i] % 2 != 0) oddCount++;
  }
  if (len % 2 == 0 && oddCount > 0) return false;
  if (len % 2 != 0 && oddCount > 1) return false;
  return true;
}

void countAlphabet(string name) {
  for (int i = 0; i < name.length(); i++) {
    numOfAlp[name[i] - 'A']++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string name;
  cin >> name;

  countAlphabet(name);

  if (!canMakePalindrome(name.length())) {
    cout << "I'm Sorry Hansoo" << '\n';
    return 0;
  }

  int n = name.length();
  char ans[50];
  int idx = 0;
  for (int i = 0; i < 26; i++) {
    int cnt = numOfAlp[i];
    char curr = 'A' + i;
    if (cnt % 2 != 0) {
      int mid = n / 2;
      ans[mid] = curr;
    }
    for (int j = idx; j < idx + cnt / 2; j++) {
      ans[j] = curr;
      ans[name.length() - 1 - j] = curr;
    }
    idx += cnt / 2;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }

  return 0;
}