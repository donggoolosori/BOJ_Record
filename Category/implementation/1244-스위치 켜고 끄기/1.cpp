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

int N, M;
int swtch[101];

void boy(int num) {
  for (int i = num; i <= N; i += num) {
    swtch[i] = 1 - swtch[i];
  }
}

void girl(int num) {
  swtch[num] = 1 - swtch[num];
  for (int low = num - 1, high = num + 1; low > 0 && high <= N; low--, high++) {
    if (swtch[low] != swtch[high]) return;

    swtch[low] = 1 - swtch[low];
    swtch[high] = 1 - swtch[high];
  }
}

int main() {
  FAST_IO;

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> swtch[i];
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    int gender, num;
    cin >> gender >> num;
    if (gender == 1) {
      boy(num);
    } else if (gender == 2) {
      girl(num);
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << swtch[i] << ' ';
    if (i % 20 == 0) cout << '\n';
  }

  return 0;
}