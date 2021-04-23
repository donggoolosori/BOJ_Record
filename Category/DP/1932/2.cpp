#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int triangle[500][500];
int cache[500][500];

int getMaxScore(int y, int x)
{
    if (y == N - 1)
        return triangle[y][x];

    int &ret = cache[y][x];
    if (ret != -1)
        return ret;

    return ret = max(getMaxScore(y + 1, x), getMaxScore(y + 1, x + 1)) + triangle[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];

    cout << getMaxScore(0, 0) << '\n';

    return 0;
}