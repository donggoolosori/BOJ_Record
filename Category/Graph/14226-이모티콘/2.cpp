// 0ms
#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

bool visit[MAX + 1][MAX + 1];

struct Node {
  int display, clip_board, time;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int s;
  cin >> s;

  int minTime = MAX;
  queue<Node> q;
  q.push({1, 0, 0});
  visit[1][0] = true;

  while (!q.empty()) {
    int display = q.front().display, clip_board = q.front().clip_board,
        time = q.front().time;
    q.pop();

    if (display == s) {
      cout << time << '\n';
      return 0;
    }

    // 화면에 있는 이모티콘 복사해서 클립보드에 저장
    if (display <= MAX && !visit[display][display]) {
      visit[display][display] = true;
      q.push({display, display, time + 1});
    }
    // 클립보드에 있는 이모티콘을 화면에 붙여넣기
    if (display + clip_board <= MAX &&
        !visit[display + clip_board][clip_board]) {
      visit[display + clip_board][clip_board] = true;
      q.push({display + clip_board, clip_board, time + 1});
    }
    // 화면에 있는 이모티콘 1개 삭제
    if (display > 0 && !visit[display - 1][clip_board]) {
      visit[display - 1][clip_board] = true;
      q.push({display - 1, clip_board, time + 1});
    }
  }

  return 0;
}