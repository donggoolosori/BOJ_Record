#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n, m;
    cin >> n >> m;
    vector<long long int> tree(n);
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    sort(tree.begin(), tree.end());

    long long int left = 0, right = tree[n - 1];
    long long int result = 0;
    while (left <= right)
    {
        long long int mid = (left + right) / 2;
        long long int meter = 0;
        for (int i = 0; i < n; i++)
        {
            meter += (tree[i] - mid) > 0 ? (tree[i] - mid) : 0;
        }
        if (meter >= m)
        {
            left = mid + 1;
            result = max(result, mid);
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result;

    return 0;
}