#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int num[100001];
int n, m;
void binarySearch(int a)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (num[mid] == a)
        {
            cout << 1 << '\n';
            return;
        }
        else if (num[mid] > a)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << 0 << '\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num + n);
    cin >> m;

    int a;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        binarySearch(a);
    }
    return 0;
}