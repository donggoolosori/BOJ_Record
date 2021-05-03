#include <iostream>

using namespace std;

const int INF = 987654321;
int N, M;
int maps[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 초기화
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                maps[i][j] = 0;
            else
                maps[i][j] = INF;
        }

    int fr, to, cost;
    while (M--)
    {
        cin >> fr >> to >> cost;
        if (maps[fr][to] > cost)
            maps[fr][to] = cost;
    }

    // 플로이드 워셜
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (maps[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << maps[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}