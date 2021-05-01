#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1000000];

inline int getLisLength()
{
    vector<int> lis;
    lis.push_back(arr[0]);

    for (int i = 1; i < N; i++)
    {
        if (lis.back() < arr[i])
            lis.push_back(arr[i]);
        else
        {
            auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
            *iter = arr[i];
        }
    }

    return lis.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << getLisLength() << '\n';

    return 0;
}