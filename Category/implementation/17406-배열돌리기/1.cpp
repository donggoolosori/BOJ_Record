#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

struct Op {
  int r, c, s;
};
int originArr[51][51];
int N, M, K;
Op ops[6];

void rotate(vector<vector<int>> &arr, int r, int c, int s) {
  for (int i = 1; i <= s; i++) {
    int next = arr[r - i][c - i];
    // up
    for (int j = c - i + 1; j <= c + i; j++) {
      int temp = arr[r - i][j];
      arr[r - i][j] = next;
      next = temp;
    }
    // right
    for (int j = r - i + 1; j <= r + i; j++) {
      int temp = arr[j][c + i];
      arr[j][c + i] = next;
      next = temp;
    }
    // down
    for (int j = c + i - 1; j >= c - i; j--) {
      int temp = arr[r + i][j];
      arr[r + i][j] = next;
      next = temp;
    }
    // left
    for (int j = r + i - 1; j >= r - i; j--) {
      int temp = arr[j][c - i];
      arr[j][c - i] = next;
      next = temp;
    }
  }
}

int getMinVal(vector<vector<int>> &arr) {
  int ret = 2e9;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= M; j++) {
      sum += arr[i][j];
    }
    ret = min(ret, sum);
  }
  return ret;
}

int main() {
  FAST_IO;

  cin >> N >> M >> K;

  vector<vector<int>> arr(N + 1, vector<int>(M + 1));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> arr[i][j];
    }
  }

  vector<int> order(K);

  for (int i = 0; i < K; i++) {
    order[i] = i;
    int r, c, s;
    cin >> r >> c >> s;
    ops[i] = {r, c, s};
  }

  int ans = 2e9;

  do {
    vector<vector<int>> newArr(N + 1, vector<int>(M + 1));
    copy(arr.begin(), arr.end(), newArr.begin());

    for (int i = 0; i < K; i++) {
      Op op = ops[order[i]];
      int r = op.r, s = op.s, c = op.c;
      rotate(newArr, r, c, s);
    }
    ans = min(ans, getMinVal(newArr));
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << '\n';

  return 0;
}