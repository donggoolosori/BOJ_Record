#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 1000;
int N;
int matrix[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  // 초기화
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 0) matrix[i][j] = INF;
    }

  // 플로이드 워셜 알고리즘 사용
  for (int bridge = 1; bridge <= N; bridge++) {
    for (int fr = 1; fr <= N; fr++) {
      for (int to = 1; to <= N; to++) {
        matrix[fr][to] =
            min(matrix[fr][to], matrix[fr][bridge] + matrix[bridge][to]);
      }
    }
  }

  // 결과 출력
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (matrix[i][j] == INF)
        cout << 0 << ' ';
      else
        cout << 1 << ' ';
    }
    cout << '\n';
  }

  return 0;
}