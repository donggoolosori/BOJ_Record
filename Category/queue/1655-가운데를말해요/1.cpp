#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define INF 987654321
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int main() {
  FAST_IO;

  cin >> N;

  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    if (maxHeap.size() == minHeap.size()) {
      maxHeap.push(num);
    } else if (maxHeap.size() == minHeap.size() + 1) {
      minHeap.push(num);
    }

    if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
      int maxTop = maxHeap.top(), minTop = minHeap.top();
      maxHeap.pop(), minHeap.pop();
      maxHeap.push(minTop), minHeap.push(maxTop);
    }

    cout << maxHeap.top() << '\n';
  }

  return 0;
}