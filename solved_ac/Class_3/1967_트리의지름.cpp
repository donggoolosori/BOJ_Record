#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct NODE
{
    int idx;
    int w;
};
int max_idx, max_w;
vector<NODE> graph[10001];
bool visit[10001];

void dfs(int idx, int w)
{
    if (visit[idx])
        return;
    visit[idx] = true;
    if (w > max_w)
    {
        max_w = w;
        max_idx = idx;
    }
    for (int i = 0; i < graph[idx].size(); i++)
    {
        int nIdx = graph[idx][i].idx;
        int nW = graph[idx][i].w;
        dfs(nIdx, nW + w);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int fr, to, w;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> fr >> to >> w;
        graph[fr].push_back({to, w});
        graph[to].push_back({fr, w});
    }

    dfs(1, 0);
    memset(visit, false, sizeof(visit));
    max_w = 0;
    dfs(max_idx, 0);

    cout << max_w << '\n';

    return 0;
}