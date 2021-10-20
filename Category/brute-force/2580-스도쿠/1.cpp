// 212ms
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int board[9][9], flag;
vector<pair<int, int>> empties;

void printBoard() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}

bool canLocate(int cand, int y, int x) {
  for (int i = 0; i < 9; i++) {
    // 가로
    if (board[y][i] == cand) return false;
    // 세로
    if (board[i][x] == cand) return false;
  }
  // 격자
  int sy = (y / 3) * 3, sx = (x / 3) * 3;
  for (int i = sy; i < sy + 3; i++) {
    for (int j = sx; j < sx + 3; j++) {
      if (board[i][j] == cand) return false;
    }
  }
  return true;
}

void dfs(int L) {
  if (flag) return;
  if (L == empties.size()) {
    printBoard();
    flag = true;
    return;
  }

  int y = empties[L].first, x = empties[L].second;
  for (int cand = 1; cand <= 9; cand++) {
    if (!canLocate(cand, y, x)) continue;

    board[y][x] = cand;
    dfs(L + 1);
    board[y][x] = 0;
  }
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) empties.push_back({i, j});
    }
  }
}

int main() {
  input();
  dfs(0);

  return 0;
}