#include <iostream>
#include <queue>
#include <string>

using namespace std;

string bfs(int n) {
  int cnt = 0;
  queue<string> q;
  for (int i = 0; i <= 9; i++) q.push(to_string(i));
  while (!q.empty()) {
    string curr = q.front();
    q.pop();
    if (cnt == n) return curr;
    cnt++;

    for (char i = '0'; i < curr.back(); i++) {
      q.push(curr + i);
    }
  }
  return "";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  string answer = bfs(N);
  if (answer.empty())
    cout << -1;
  else
    cout << answer;

  return 0;
}