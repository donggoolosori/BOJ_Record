#include <vector>
#include <iostream>
#include <cstring>
#define MAX 100001

using namespace std;

int N, far_idx, maxDist;
struct Node
{
    int idx, dist;
};
vector<Node> tree[MAX];
bool visit[MAX];

void dfs(int curr, int sum)
{
    if (visit[curr])
        return;
    visit[curr] = true;

    if (maxDist < sum)
    {
        maxDist = sum;
        far_idx = curr;
    }

    for (const auto &next : tree[curr])
    {
        int nextDist = next.dist;
        dfs(next.idx, nextDist + sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int fr, to, w;
    for (int i = 1; i <= N; i++)
    {
        cin >> fr;
        while (true)
        {
            cin >> to;
            if (to == -1)
                break;
            cin >> w;
            tree[fr].push_back({to, w});
            tree[to].push_back({fr, w});
        }
    }

    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    maxDist = 0;
    dfs(far_idx, 0);

    cout << maxDist << '\n';

    return 0;
}