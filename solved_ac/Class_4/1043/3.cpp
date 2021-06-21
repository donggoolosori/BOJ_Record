#include <iostream>
#include <vector>

using namespace std;

int parent[51];
vector<int> party[51];
int N, M;

int getParent(int x) {
  if (parent[x] == x) return x;
  if (parent[x] == 0) return 0;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a > b) swap(a, b);
  parent[b] = a;
}

bool compareParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a == b) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int numOfKnowing, know, numOfParty;
  // N,M 입력
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }
  // 진실 아는 사람 입력
  cin >> numOfKnowing;
  for (int i = 0; i < numOfKnowing; i++) {
    cin >> know;
    parent[know] = 0;
  }
  // 파티 참가자 입력
  for (int i = 0; i < M; i++) {
    cin >> numOfParty;
    int prev, curr;
    for (int j = 0; j < numOfParty; j++) {
      if (j > 0) {
        prev = curr;
        cin >> curr;
        unionParent(prev, curr);
      } else {
        cin >> curr;
      }
      party[i].push_back(curr);
    }
  }
  int answer = 0;
  for (int i = 0; i < M; i++) {
    bool flag = true;
    for (const auto &person : party[i]) {
      if (!flag) break;
      if (getParent(person) == 0) {
        flag = false;
        break;
      }
    }
    if (!flag) continue;
    answer++;
  }

  cout << answer << '\n';

  return 0;
}