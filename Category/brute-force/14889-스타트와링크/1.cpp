#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, stats[20][20], team[20], ans = 2e9;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> stats[i][j];
    }
  }
}

int getStat(const vector<int> &team) {
  int stat = 0;
  for (int i = 0; i < team.size(); i++) {
    for (int j = i + 1; j < team.size(); j++) {
      int a = team[i], b = team[j];
      stat += stats[a][b] + stats[b][a];
    }
  }

  return stat;
}

int getDiff() {
  vector<int> start, link;
  for (int i = 0; i < n; i++) {
    if (team[i])
      start.push_back(i);
    else
      link.push_back(i);
  }
  int start_stat = getStat(start);
  int link_stat = getStat(link);
  return abs(start_stat - link_stat);
}

void makeTeam(int L, int idx) {
  if (L == n / 2) {
    int diff = getDiff();
    if (diff < ans) ans = diff;
    return;
  }
  for (int i = idx; i < n; i++) {
    if (team[i]) continue;
    team[i] = true;
    makeTeam(L + 1, i + 1);
    team[i] = false;
  }
}

int main() {
  input();

  makeTeam(0, 0);

  cout << ans << '\n';

  return 0;
}