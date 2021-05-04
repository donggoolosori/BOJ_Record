// 5932kb 956ms
#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, M, X;
int graph[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    int s, e, t;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            graph[i][j] = INF;
        }

    while (M--)
    {
        cin >> s >> e >> t;
        graph[s][e] = t;
    }

    // 플로이드워셜 알고리즘
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, graph[i][X] + graph[X][i]);
    cout << ans << '\n';

    return 0;
}