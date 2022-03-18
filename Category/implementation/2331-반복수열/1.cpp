#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

ll A, P;

int main() {
  FAST_IO;

  unordered_map<ll, int> um;

  cin >> A >> P;

  for (int i = 0;; i++) {
    if (um.count(A) != 0) {
      cout << um[A] << '\n';
      return 0;
    }
    um[A] = i;

    string sNum = to_string(A);
    ll next = 0;
    for (int i = 0; i < (int)sNum.length(); i++) {
      next += pow(sNum[i] - '0', P);
    }
    A = next;
  }

  return 0;
}