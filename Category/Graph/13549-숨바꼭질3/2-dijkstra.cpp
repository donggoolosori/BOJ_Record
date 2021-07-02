#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001

using namespace std;

int n, k;
bool visit[MAX];
int dist[MAX];

int dijkstra() {
  for (int i = 0; i <= MAX; i++) dist[i] = MAX;
  dist[n] = 0;
  visit[n] = true;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, n});

  while (!pq.empty()) {
    int curr = pq.top().second, time = pq.top().first;
    pq.pop();

    if (dist[curr] < time) continue;

    if (curr < k && curr * 2 < MAX && !visit[curr * 2] &&
        dist[curr * 2] > time) {
      dist[curr * 2] = time;
      visit[curr * 2] = true;
      pq.push({time, curr * 2});
    }
    if (curr < k && !visit[curr + 1] && dist[curr + 1] > time + 1) {
      dist[curr + 1] = time + 1;
      visit[curr + 1] = true;
      pq.push({time + 1, curr + 1});
    }
    if (curr > 1 && !visit[curr - 1] && dist[curr - 1] > time + 1) {
      dist[curr - 1] = time + 1;
      visit[curr - 1] = true;
      pq.push({time + 1, curr - 1});
    }
  }
  return dist[k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  if (n >= k) {
    cout << n - k;
    return 0;
  }
  cout << dijkstra();

  return 0;
}