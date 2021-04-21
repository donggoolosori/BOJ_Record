#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[1000], numbers[1000];
int n;

int lis(int start)
{
    int &ret = cache[start];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int next = start + 1; next < n; next++)
        if (numbers[start] < numbers[next])
            ret = max(ret, lis(next) + 1);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int maxLen = 0;
    for (int i = 0; i < n; i++)
        maxLen = max(maxLen, lis(i));
    cout << maxLen << '\n';

    return 0;
}