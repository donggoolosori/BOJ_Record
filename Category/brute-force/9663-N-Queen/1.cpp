#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, board[15];

bool canLocate(int row) {
  for (int i = 0; i < row; i++) {
    if (board[i] == board[row]) return false;
    if (abs(board[row] - board[i]) == row - i) return false;
  }
  return true;
}

int dfs(int row) {
  if (row == n) {
    return 1;
  }

  int cnt = 0;
  for (int col = 0; col < n; col++) {
    board[row] = col;
    if (canLocate(row)) cnt += dfs(row + 1);
  }
  return cnt;
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
}

int main() {
  input();
  cout << dfs(0) << '\n';
  return 0;
}