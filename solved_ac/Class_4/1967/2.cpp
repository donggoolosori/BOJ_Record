#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, maxR, farIdx;
struct Node
{
    int idx, w;
};
vector<Node> tree[10001];
bool visit[10001];

void dfs(int curr, int sum)
{
    if (visit[curr])
        return;
    visit[curr] = true;

    if (sum > maxR)
    {
        maxR = sum;
        farIdx = curr;
    }

    for (const auto &next : tree[curr])
        dfs(next.idx, next.w + sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int p, c, w;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> p >> c >> w;
        tree[p].push_back({c, w});
        tree[c].push_back({p, w});
    }

    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    maxR = 0;
    dfs(farIdx, 0);
    cout << maxR << '\n';
    return 0;
}