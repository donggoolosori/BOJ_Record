#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    int min1 = 50;
    int min2 = 100;
    int min3 = 150;
    int max1 = 0;
    int num[6];
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> num[i];
        max1 = max(max1, num[i]);
        sum += num[i];
    }
    num[0] = min(num[0], num[5]);
    num[1] = min(num[1], num[4]);
    num[2] = min(num[2], num[3]);
    sort(num, num + 3);
    min3 = num[0] + num[1] + num[2];
    min2 = num[0] + num[1];
    min1 = num[0];

    long long int res;
    if (n == 1)
        res = sum - max1;
    else
    {
        long long int n1, n2, n3 = 4;
        n2 = 8 * n - 12;
        n1 = 4 * (n - 1) * (n - 2) + (n - 2) * (n - 2);
        res = n3 * min3 + n2 * min2 + n1 * min1;
    }
    cout << res;

    return 0;
}
