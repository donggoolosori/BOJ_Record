#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int N, K, cnt = 0;
deque<int> strength, robots;

void step1() {
  strength.push_front(strength.back());
  strength.pop_back();

  robots.push_front(robots.back());
  robots.pop_back();

  robots[N - 1] = 0;
}

void step2() {
  for (int i = N - 2; i >= 0; i--) {
    if (robots[i] == 0) continue;
    if (strength[i + 1] <= 0 || robots[i + 1]) continue;

    robots[i] = 0, robots[i + 1] = 1;

    if (--strength[i + 1] == 0) cnt++;

    if (i + 1 == N - 1) {
      robots[N - 1] = 0;
    }
  }
}

void step3() {
  if (strength.front() > 0 && !robots.front()) {
    robots[0] = 1;

    if (--strength.front() == 0) cnt++;
  }
}

void steps() {
  step1();
  step2();
  step3();
}

int main() {
  FAST_IO;
  cin >> N >> K;

  robots.resize(2 * N);

  for (int i = 0; i < 2 * N; i++) {
    int x;
    cin >> x;
    strength.push_back(x);
  }

  int step = 0;

  while (cnt < K) {
    steps();
    step++;
  }

  cout << step << '\n';

  return 0;
}