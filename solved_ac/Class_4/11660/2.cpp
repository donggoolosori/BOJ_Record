#include <iostream>

using namespace std;

int N, M;
int table[1025][1025], pSum[1025][1025];

inline void setPartialSum()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            pSum[i][j] = pSum[i][j - 1] + pSum[i - 1][j] - pSum[i - 1][j - 1] + table[i][j];
}

int getRangeSum(int y1, int x1, int y2, int x2)
{
    int sum = pSum[y2][x2];
    sum -= pSum[y2][x1 - 1];
    sum -= pSum[y1 - 1][x2];
    sum += pSum[y1 - 1][x1 - 1];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> table[i][j];

    // 부분합 생성
    setPartialSum();

    int y1, x1, y2, x2;
    while (M--)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << getRangeSum(y1, x1, y2, x2) << '\n';
    }

    return 0;
}