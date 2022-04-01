#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long
#define MAX 12

using namespace std;

int N, K;
int boardColor[MAX + 1][MAX + 1];
int dy[] = {0, 0, -1, 1}, dx[] = {1, -1, 0, 0};
string board[MAX + 1][MAX + 1];
struct Piece {
  int dir, y, x;
};
Piece pieces[10];

int main() {
  FAST_IO;

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> boardColor[i][j];
    }
  }

  for (int i = 0; i < K; i++) {
    int y, x, d;
    cin >> y >> x >> d;
    board[y][x] += to_string(i);
    pieces[i] = {d - 1, y, x};
  }

  for (int turn = 1; turn <= 1000; turn++) {
    for (int id = 0; id < 10; id++) {
      int y = pieces[id].y, x = pieces[id].x, dir = pieces[id].dir;

      int ny = y + dy[dir], nx = x + dx[dir];

      if (ny <= 0 || nx <= 0 || ny > N || nx > N || boardColor[ny][nx] == 2) {
        if (dir == 0 || dir == 1) {
          dir = 1 - dir;
        } else if (dir == 2) {
          dir = 3;
        } else if (dir == 3) {
          dir = 2;
        }
        pieces[id].dir = dir;
      }

      ny = y + dy[dir], nx = x + dx[dir];

      if (ny <= 0 || nx <= 0 || ny > N || nx > N || boardColor[ny][nx] == 2) {
        continue;
      }

      int nextColor = boardColor[ny][nx];

      int index = board[y][x].find(to_string(id));
      string move = board[y][x].substr(index);
      board[y][x] = board[y][x].substr(0, index);

      if (nextColor == 1) {
        reverse(move.begin(), move.end());
      }

      board[ny][nx] += move;

      for (const auto &ch : move) {
        pieces[ch - '0'].y = ny, pieces[ch - '0'].x = nx;
      }

      if (board[ny][nx].length() >= 4) {
        cout << turn << '\n';
        return 0;
      }
    }
  }

  cout << -1 << '\n';

  return 0;
}