#include <iostream>
#include <queue>
#include <vector>

#define max(a, b) a > b ? a : b
#define INF 987654321

using namespace std;

int n, m, r;
int item[101];
vector<pair<int, int>> dist[101];
int ans;

void input()
{
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    // item 개수 입력
    for (int i = 1; i <= n; i++)
        cin >> item[i];

    // 지역 사이의 거리 입력
    for (int i = 0; i < r; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        dist[a].push_back(make_pair(b, d));
        dist[b].push_back(make_pair(a, d));
    }
}

void dijkstra()
{
    for (int start = 1; start <= n; start++)
    {
        vector<int> dp(n + 1, INF);
        dp[start] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, start));
        while (!pq.empty())
        {
            pair<int, int> cur = pq.top();
            pq.pop();
            int cur_dist = -cur.first;
            int cur_idx = cur.second;

            if (cur_dist > dp[cur_idx])
                continue;
            for (int i = 0; i < dist[cur_idx].size(); i++)
            {
                int next_idx = dist[cur_idx][i].first;
                int next_dist = dist[cur_idx][i].second;
                if (next_dist + cur_dist < dp[next_idx])
                {
                    dp[next_idx] = next_dist + cur_dist;
                    pq.push(make_pair(-dp[next_idx], next_idx));
                }
            }
        }
        // 범위 m 보다 짧은거리에 있는 지역의 item만 더하기
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] <= m)
                sum += item[i];
        }
        ans = max(ans, sum);
    }
}

int main()
{
    input();
    dijkstra();
    cout << ans << '\n';

    return 0;
}