#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int arr[1000], cache[1001];

int lis(int start)
{
    int &ret = cache[start + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int next = start + 1; next < N; next++)
        if (start == -1 || arr[start] > arr[next])
            ret = max(ret, lis(next) + 1);
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
    cout << lis(-1) - 1 << '\n';
    return 0;
}