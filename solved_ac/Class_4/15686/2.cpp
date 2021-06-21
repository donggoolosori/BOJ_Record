#include <algorithm>
#include <cstdlib>  // abs
#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
int city[51][51];
int N, M, minDist = INF;
struct Pos {
  int y, x;
};
vector<Pos> house, chicken;

int getChickenDistance(vector<Pos> &choice) {
  int ret = 0;
  for (const auto &h : house) {
    int sum = INF;
    for (const auto &c : choice)
      sum = min(sum, (abs(h.y - c.y) + abs(h.x - c.x)));
    ret += sum;
  }
  return ret;
}

void chooseChicken(vector<Pos> &choice, int L, int idx) {
  if (L == M) {
    minDist = min(minDist, getChickenDistance(choice));
    return;
  }
  for (int i = idx; i < chicken.size(); i++) {
    choice.push_back(chicken[i]);
    chooseChicken(choice, L + 1, i + 1);
    choice.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  // 입력
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      cin >> city[i][j];
      if (city[i][j] == 1)
        house.push_back({i, j});
      else if (city[i][j] == 2)
        chicken.push_back({i, j});
    }
  vector<Pos> temp;
  chooseChicken(temp, 0, 0);
  cout << minDist << '\n';

  return 0;
}