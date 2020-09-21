#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int card[500001];
int n;
int lower_binary(int target)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (card[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}

int upper_binary(int target)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (card[mid] > target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }
    sort(card, card + n);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        int lower = lower_binary(a);
        int upper = upper_binary(a);
        cout << upper << ' ' << lower << ' ' << a << '\n';
        if (upper == n - 1 && a == card[n - 1])
            upper++;
        // cout << upper - lower << ' ';
    }
    return 0;
}