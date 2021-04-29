#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[1001], numbers[1000];
int n;

int lis(int start)
{
    int &ret = cache[start + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int next = start + 1; next < n; next++)
        if (start == -1 || (numbers[start] < numbers[next]))
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

    cout << lis(-1) - 1 << '\n';

    return 0;
}