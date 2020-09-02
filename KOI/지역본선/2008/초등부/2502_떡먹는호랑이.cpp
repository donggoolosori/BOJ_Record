#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, k;
    cin >> d >> k;
    vector<int> x(d + 1, 0);
    vector<int> y(d + 1, 0);
    x[1] = 1;
    x[2] = 0;
    y[1] = 0;
    y[2] = 1;
    for (int i = 3; i < d + 1; i++)
    {
        x[i] = x[i - 1] + x[i - 2];
        y[i] = y[i - 1] + y[i - 2];
    }
    for (int i = 1; i < k + 1; i++)
    {
        for (int j = i; j < k + 1; j++)
        {
            if (x[d] * i + y[d] * j == k)
            {
                cout << i << '\n'
                     << j;
                return 0;
            }
        }
    }

    return 0;
}