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

int N;
int check[9], selected[9];

void printPermutations(int depth) {
  if (depth == N) {
    for (int i = 0; i < N; i++) {
      cout << selected[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (check[i]) continue;
    check[i] = true;
    selected[depth] = i;
    printPermutations(depth + 1);
    check[i] = false;
  }
}

int main() {
  FAST_IO;

  cin >> N;

  printPermutations(0);

  return 0;
}