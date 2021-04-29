#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int stiker[2][100000];
int cache[2][100000];
int N;

int getMaxScore(int y, int x)
{
    if (x >= N)
        return 0;
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;

    ret = 0;

    ret = max(ret, getMaxScore(1 - y, x + 1) + stiker[y][x]);
    ret = max(ret, getMaxScore(1 - y, x + 2) + stiker[y][x]);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        // 입력
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < N; j++)
                cin >> stiker[i][j];
        cout << max(getMaxScore(0, 0), getMaxScore(1, 0)) << '\n';
    }

    return 0;
}