#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int R, C, K, r, c;
int arr[101][101];

bool compare(PII &a, PII &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

void operR() {
  int maxCol = 0;

  for (int i = 1; i <= r; i++) {
    map<int, int> counter;

    for (int j = 1; j <= c; j++) {
      if (arr[i][j] == 0) continue;
      counter[arr[i][j]]++;
    }

    vector<pair<int, int>> vec(counter.begin(), counter.end());
    sort(vec.begin(), vec.end(), compare);

    maxCol = max(maxCol, (int)(vec.size() * 2));

    for (int idx = 0; idx < vec.size() && idx < 50; idx++) {
      arr[i][idx * 2 + 1] = vec[idx].first;
      arr[i][idx * 2 + 2] = vec[idx].second;
    }
    for (int idx = vec.size() * 2 + 1; idx <= 100; idx++) {
      arr[i][idx] = 0;
    }
  }

  if (maxCol > 100) maxCol = 100;

  c = maxCol;
}

void operC() {
  int maxRow = 0;

  for (int i = 1; i <= c; i++) {
    map<int, int> counter;
    for (int j = 1; j <= r; j++) {
      if (arr[j][i] == 0) continue;
      counter[arr[j][i]]++;
    }

    vector<pair<int, int>> vec(counter.begin(), counter.end());
    sort(vec.begin(), vec.end(), compare);

    maxRow = max(maxRow, (int)(vec.size() * 2));

    for (int idx = 0; idx < vec.size() && idx < 50; idx++) {
      arr[idx * 2 + 1][i] = vec[idx].first;
      arr[idx * 2 + 2][i] = vec[idx].second;
    }
    for (int idx = vec.size() * 2 + 1; idx <= 100; idx++) {
      arr[idx][i] = 0;
    }
  }

  if (maxRow > 100) maxRow = 100;

  r = maxRow;
}

int main() {
  FAST_IO;

  cin >> R >> C >> K;
  r = 3, c = 3;

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> arr[i][j];
    }
  }

  for (int time = 0; time <= 100; time++) {
    if (arr[R][C] == K) {
      cout << time << '\n';
      return 0;
    }

    if (r >= c) {
      operR();
    } else {
      operC();
    }
  }

  cout << -1 << '\n';

  return 0;
}