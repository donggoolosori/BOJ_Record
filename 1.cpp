#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define INF 987654321
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define matrix vector<vector<ll>>

using namespace std;

ll D;
const int MOD = 1e9 + 7;

matrix operator*(matrix const& A, matrix const& B) {
  matrix ret(A.size(), vector<ll>(B[0].size()));

  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B[0].size(); j++) {
      for (int k = 0; k < A[0].size(); k++) {
        ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }

  return ret;
}

matrix pow(matrix a, int n) {
  matrix ret(a.size(), vector<ll>(a.size()));

  for (int i = 0; i < a.size(); i++) ret[i][i] = 1;

  while (n > 0) {
    if (n & 1) {
      ret = ret * a;
    }

    a = a * a;

    n >>= 1;
  }

  return ret;
}

int main() {
  FAST_IO;

  cin >> D;

  matrix A = {{0, 1, 0, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 1, 0, 0, 0},
              {0, 1, 0, 1, 1, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 1, 0},
              {1, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0, 0, 1},
              {0, 0, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0}};

  A = pow(A, D);

  cout << A[0][0];

  return 0;
}