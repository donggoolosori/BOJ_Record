#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long size;
  cin >> size;

  cout << fixed;
  cout.precision(6);
  cout << sqrt(size) * 4;

  return 0;
}