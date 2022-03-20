#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int A, B, m;
stack<int> ANums, ans;

int AtoDec() {
  int ret = 0;

  int mul = 1;
  while (!ANums.empty()) {
    ret += ANums.top() * mul;
    ANums.pop();
    mul *= A;
  }

  return ret;
}

void decToB(int dec) {
  while (dec > 0) {
    ans.push(dec % B);
    dec /= B;
  }
}

int main() {
  FAST_IO;

  cin >> A >> B >> m;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    ANums.push(num);
  }

  decToB(AtoDec());

  while (!ans.empty()) {
    cout << ans.top() << ' ';
    ans.pop();
  }

  return 0;
}