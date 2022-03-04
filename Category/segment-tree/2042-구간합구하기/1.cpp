#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define INF 987654321
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define MAX 1000000

using namespace std;

ll tree[4 * MAX];
ll nums[MAX + 1];
int N, M, K;

ll init(int s, int e, int node) {
  if (s == e) return tree[node] = nums[s];

  int mid = (s + e) / 2;

  return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

ll sum(int s, int e, int node, const int &left, const int &right) {
  if (e < left || s > right) return 0;

  if (left <= s && e <= right) return tree[node];

  int mid = (s + e) / 2;

  return sum(s, mid, node * 2, left, right) +
         sum(mid + 1, e, node * 2 + 1, left, right);
}

void update(int s, int e, int node, const int &updateIdx, const ll &diff) {
  if (e < updateIdx || s > updateIdx) return;

  tree[node] += diff;

  if (s == e) return;

  int mid = (s + e) / 2;

  update(s, mid, node * 2, updateIdx, diff);
  update(mid + 1, e, node * 2 + 1, updateIdx, diff);
}

int main() {
  FAST_IO;

  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) cin >> nums[i];

  init(1, N, 1);

  for (int i = 0; i < M + K; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;

    if (a == 1) {
      ll diff = c - nums[b];
      nums[b] = c;
      update(1, N, 1, b, diff);
    } else if (a == 2) {
      cout << sum(1, N, 1, b, c) << '\n';
    }
  }

  return 0;
}