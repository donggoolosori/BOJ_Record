#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    float numOfShips, distance;
    cin >> numOfShips >> distance;

    int cnt = 0;
    while (numOfShips--) {
      float velocity, fuel, fuelConsumptionRate;
      cin >> velocity >> fuel >> fuelConsumptionRate;

      float maxTravelTime = fuel / fuelConsumptionRate;
      if (maxTravelTime * velocity >= distance) cnt++;
    }
    cout << cnt << '\n';
  }

  return 0;
}