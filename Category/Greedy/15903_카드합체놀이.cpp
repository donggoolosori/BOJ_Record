#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    while (m--)
    {
        sort(num.begin(), num.end());
        num[0] = num[1] = num[0] + num[1];
    }
    long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum += num[i];
    cout << sum;
    return 0;
}