#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;

int n;
char signs[9];
bool check[10];
ll maxNum, minNum = 1e10;

void dfs(int L, ll num) {
  if (L == -1) {
    for (int i = 0; i <= 9; i++) {
      check[i] = true;
      dfs(L + 1, i);
      check[i] = false;
    }
    return;
  }
  if (L == n) {
    if (maxNum < num) maxNum = num;
    if (minNum > num) minNum = num;
    return;
  }

  char sign = signs[L];
  for (int i = 0; i <= 9; i++) {
    if (check[i]) continue;
    if (sign == '<' && num % 10 > i) continue;
    if (sign == '>' && num % 10 < i) continue;

    check[i] = true;
    dfs(L + 1, num * 10 + i);
    check[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> signs[i];
  dfs(-1, 0);

  string strMaxNum = to_string(maxNum);
  string strMinNum = to_string(minNum);
  if (strMaxNum.length() == n) strMaxNum = "0" + strMaxNum;
  if (strMinNum.length() == n) strMinNum = "0" + strMinNum;
  cout << strMaxNum << '\n' << strMinNum << '\n';
  return 0;
}