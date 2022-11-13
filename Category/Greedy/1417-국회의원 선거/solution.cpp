#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PII pair<int, int>
#define ll long long

using namespace std;

int main() {
  FAST_IO;

  priority_queue<int> pq;

  int n, ret = 0, my_vote;

  cin >> n;
  cin >> my_vote;
  for (int i = 0; i < n - 1; i++) {
    int other;
    cin >> other;
    if (other >= my_vote) pq.push(other);
  }

  while (!pq.empty() && pq.top() >= my_vote) {
    int temp = pq.top();
    pq.pop();
    temp--;

    ret++;
    my_vote++;

    pq.push(temp);
  }

  cout << ret << '\n';

  return 0;
}