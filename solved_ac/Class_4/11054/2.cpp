#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int arr[1000], cache[2][1002];

int reverseLDS(int start)
{
    int &ret = cache[0][start + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int next = start - 1; next >= 0; next--)
    {
        if (start == N || arr[start] > arr[next])
            ret = max(ret, reverseLDS(next) + 1);
    }
    return ret;
}

int LDS(int start)
{
    int &ret = cache[1][start + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int next = start + 1; next < N; next++)
        if (start == -1 || arr[start] > arr[next])
            ret = max(ret, LDS(next) + 1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    reverseLDS(N);
    LDS(-1);

    for (int i = 1; i <= N; i++)
        ans = max(ans, cache[0][i] + cache[1][i] - 1);

    cout << ans << '\n';
    return 0;
}