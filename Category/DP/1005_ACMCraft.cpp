#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int n, k, w;
    while (T--)
    {
        cin >> n >> k;
        vector<int> time(n + 1);
        vector<vector<int>> node(n + 1);
        vector<int> inDegree(n + 1, 0);
        vector<int> dp(n + 1, 0);
        queue<int> q;

        // 시간 입력
        for (int i = 1; i < n + 1; i++)
            cin >> time[i];

        // 간선 정보 입력
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            node[a].push_back(b);
            inDegree[b]++;
        }
        // 목표 건물 정보 입력
        cin >> w;
        // 진입 차수가 0인 노드를 큐에 삽입
        for (int i = 1; i < n + 1; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                dp[i] = time[i];
            }
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            if (x == w)
                break;
            for (int j = 0; j < node[x].size(); j++)
            {
                int y = node[x][j];
                if (--inDegree[y] == 0)
                {
                    q.push(y);
                }
                dp[y] = max(dp[y], dp[x] + time[y]);
            }
        }
        cout << dp[w] << '\n';
    }
    return 0;
}