#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[1001];
vector<bool> visit(1001);

void dfs(int curr)
{
    visit[curr] = true;

    for (const auto &next : graph[curr])
    {
        if (visit[next])
            continue;
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int a, b;
    // graph 생성하기
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visit[i])
            continue;

        dfs(i);
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}