#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[301][2];
int stairs[301];
int N;

int getMaxScore(int idx, int check)
{
    if (idx <= 0)
        return 0;

    int &ret = cache[idx][check];
    if (ret != -1)
        return ret;

    ret = getMaxScore(idx - 2, 0) + stairs[idx];
    ret = max(ret, getMaxScore(idx - 2, 1) + stairs[idx]);
    if (check == 0)
        ret = max(ret, getMaxScore(idx - 1, 1) + stairs[idx]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> stairs[i];
    cout << max(getMaxScore(N, 0), getMaxScore(N, 1)) << '\n';
    return 0;
}