#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int n;

bool isPrime(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}

void bfs() {
  queue<int> q;
  q.push(2);
  q.push(3);
  q.push(5);
  q.push(7);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (to_string(curr).length() == n) {
      cout << curr << '\n';
      continue;
    }

    for (int i = 1; i <= 9; i++) {
      if (isPrime(curr * 10 + i)) q.push(curr * 10 + i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  bfs();

  return 0;
}