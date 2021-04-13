// 이진탐색
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

int K, N;
vector<ll> vec;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll len;
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        cin >> len;
        vec.push_back(len);
    }
    sort(vec.begin(), vec.end());
}

int main()
{
    input();
    ll left = 1, right = vec[K - 1];

    while (left <= right)
    {
        ll mid = (left + right) / 2;

        int cnt = 0;
        for (const int &l : vec)
            cnt += l / mid;
        if (cnt >= N)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << right << '\n';

    return 0;
}