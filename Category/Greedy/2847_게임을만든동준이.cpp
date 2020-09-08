#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    int cnt = 0;
    int diff;
    for (int i = n - 2; i >= 0; i--)
    {
        if (num[i + 1] <= num[i])
        {
            diff = num[i] - num[i + 1];
            cnt += diff + 1;
            num[i] -= diff + 1;
        }
    }
    cout << cnt;

    return 0;
}