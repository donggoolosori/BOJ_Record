#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int &INF = 10000;
int N, M;
int relation[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            relation[i][j] = INF;
        }
    int a, b;
    while (M--)
    {
        cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }

    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                relation[i][j] = min(relation[i][j], relation[i][k] + relation[k][j]);

    // 최소 케빈 베이컨 수 구하기
    int ans, minKB = INF;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            sum += relation[i][j];
        }
        if (minKB > sum)
        {
            minKB = sum;
            ans = i;
        }
    }

    cout << ans << '\n';
    return 0;
}