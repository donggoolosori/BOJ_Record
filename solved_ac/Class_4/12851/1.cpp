#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;

int subin, bro;
priority_queue<int> candidate;
int visit[MAX];
struct Node
{
    int idx, dist;
};
int minTime = MAX, cnt;

void bfs()
{
    queue<Node> q;
    q.push({subin, 0});

    while (!q.empty())
    {
        int idx = q.front().idx, dist = q.front().dist;
        q.pop();
        visit[idx] = true;

        if (dist > minTime)
            continue;

        if (idx == bro)
        {
            minTime = dist;
            cnt++;
            continue;
        }

        int nIdx, nDist = dist + 1;

        nIdx = 2 * idx;
        if (nIdx < 2 * bro && nIdx < MAX && !visit[nIdx])
            q.push({nIdx, nDist});
        nIdx = idx + 1;
        if (nIdx <= bro && !visit[nIdx])
            q.push({nIdx, nDist});
        nIdx = idx - 1;
        if (nIdx >= 0 && !visit[nIdx])
            q.push({nIdx, nDist});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> subin >> bro;

    if (subin >= bro)
    {
        cout << subin - bro << '\n'
             << 1 << '\n';
        return 0;
    }

    bfs();
    cout << minTime << '\n'
         << cnt << '\n';

    return 0;
}