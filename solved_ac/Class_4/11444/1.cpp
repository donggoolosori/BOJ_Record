#include <iostream>
#include <vector>
#define ll long long
#define matrix vector<vector<ll>>
#define MOD 1000000007

using namespace std;

matrix operator*(const matrix &a, const matrix &b) {
  matrix ret(2, vector<ll>(2));

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        ret[i][j] += a[i][k] * b[k][j];
      }
      ret[i][j] %= MOD;
    }
  }

  return ret;
}

matrix pow(matrix a, ll n) {
  if (n == 1 || n == 0) return a;

  matrix temp = pow(a, n / 2);
  if (n % 2 == 0) {
    return temp * temp;
  } else {
    return temp * temp * a;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll N;
  cin >> N;
  matrix a = {{1, 1}, {1, 0}};
  matrix res = pow(a, N - 1);
  cout << (res[1][0] + res[1][1]) % MOD;

  return 0;
}