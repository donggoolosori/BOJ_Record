// 답은 맞는데 입출력 문제
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int board[9][9];
map<pair<int, int>, bool> isUsedDomino;
bool found = false;

void showBoard() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j];
    }
    cout << '\n';
  }
}

bool check(int cand, int y, int x) {
  for (int i = 0; i < 9; i++) {
    // 가로
    if (i != x && board[y][i] == cand) return false;
    // 세로
    if (i != y && board[i][x] == cand) return false;
  }
  // 격자
  int sy = (y / 3) * 3, sx = (x / 3) * 3;
  for (int i = sy; i < sy + 3; i++) {
    for (int j = sx; j < sx + 3; j++) {
      if (!(i == y && j == x) && board[i][j] == cand) return false;
    }
  }
  return true;
}

void dfs(int idx) {
  if (found) return;

  if (idx == 81) {
    found = true;
    showBoard();
    return;
  }

  int y = idx / 9, x = idx % 9;

  if (board[y][x] != 0) {
    dfs(idx + 1);
    return;
  }

  if (y < 8 && board[y + 1][x] == 0) {
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        if (i == j || isUsedDomino[{i, j}]) continue;

        board[y][x] = i, board[y + 1][x] = j;

        if (check(i, y, x) && check(j, y + 1, x)) {
          isUsedDomino[{i, j}] = true;
          dfs(idx + 1);
          isUsedDomino[{i, j}] = false;
        }

        board[y][x] = 0, board[y + 1][x] = 0;
      }
    }
  }

  if (x < 8 && board[y][x + 1] == 0) {
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        if (i == j || isUsedDomino[{i, j}]) continue;

        board[y][x] = i, board[y][x + 1] = j;

        if (check(i, y, x) && check(j, y, x + 1)) {
          isUsedDomino[{i, j}] = true;
          dfs(idx + 2);
          isUsedDomino[{i, j}] = false;
        }

        board[y][x] = 0, board[y][x + 1] = 0;
      }
    }
  }
}

bool input() {
  int n;
  cin >> n;
  if (n == 0) return false;

  int a, b;
  string pos_a, pos_b;
  while (n--) {
    cin >> a >> pos_a >> b >> pos_b;
    int ay = pos_a[0] - 'A', by = pos_b[0] - 'A';
    int ax = pos_a[1] - '0' - 1, bx = pos_b[1] - '0' - 1;
    board[ay][ax] = a, board[by][bx] = b;
    isUsedDomino[{a, b}] = true;
    isUsedDomino[{b, a}] = true;
  }
  string num_pos;
  for (int i = 1; i <= 9; i++) {
    cin >> num_pos;
    int y = num_pos[0] - 'A', x = num_pos[1] - '0' - 1;
    board[y][x] = i;
  }

  return true;
}

void solve() {
  int stage = 1;
  while (true) {
    memset(board, 0, sizeof(board));
    isUsedDomino.clear();

    if (!input()) break;

    cout << "Puzzle" << ' ' << stage << '\n';
    dfs(0);
    stage++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}