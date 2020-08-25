#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> time(n);

    for (int i = 0; i < n; i++)
        cin >> time[i];
    sort(time.begin(), time.end());
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            res += time[j];
        }
    }
    cout << res;

    return 0;
}