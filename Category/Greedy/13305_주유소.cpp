#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> road_length(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> road_length[i];

    int fuel;
    int MIN = 1000000000;
    long long int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> fuel;
        MIN = min(fuel, MIN);
        res += MIN * road_length[i];
    }

    cout << res;
    return 0;
}