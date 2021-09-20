#include <iostream>
#include <unordered_map>
#include <vector>
#define MAX 100

using namespace std;

int schedule[MAX], plug[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> schedule[i];
  }

  int answer = 0;
  for (int i = 0; i < k; i++) {
    bool needSubstitute = true;
    for (int j = 0; j < n; j++) {
      // 이미 기기가 플러그에 꽂혀있는 경우
      if (schedule[i] == plug[j]) {
        needSubstitute = false;
        break;
      }
      // 플러그가 빈 경우
      if (plug[j] == 0) {
        needSubstitute = false;
        plug[j] = schedule[i];
        break;
      }
    }

    // 교체 필요없으면 continue
    if (!needSubstitute) continue;

    // 가장 나중에 사용되거나 사용되지 않을 기기의 플러그 위치 찾음
    // (교체 할 플러그)
    int idx, maxIdx = -1;
    for (int j = 0; j < n; j++) {
      int lastIdx = 0;
      for (int m = i + 1; m < k; m++) {
        if (plug[j] == schedule[m]) break;
        lastIdx++;
      }

      if (lastIdx > maxIdx) {
        idx = j;
        maxIdx = lastIdx;
      }
    }

    plug[idx] = schedule[i];
    answer++;
  }

  cout << answer;

  return 0;
}