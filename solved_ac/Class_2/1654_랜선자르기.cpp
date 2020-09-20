#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<long long int> lan(k);
    for (int i = 0; i < k; i++)
    {
        cin >> lan[i];
    }
    sort(lan.begin(), lan.end());
    long long int left = 1, right = lan[lan.size() - 1];

    while (left <= right)
    {
        long long int mid = (left + right) / 2;
        long long int temp = 0;
        for (int i = 0; i < k; i++)
            temp += lan[i] / mid;

        if (temp >= n)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << right << '\n';

    return 0;
}