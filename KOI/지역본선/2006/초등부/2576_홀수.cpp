#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int MIN = 101;
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 1)
        {
            sum += a;
            MIN = min(a, MIN);
        }
    }
    if (MIN == 101)
    {
        cout << -1;
    }
    else
    {
        cout << sum << '\n'
             << MIN;
    }

    return 0;
}