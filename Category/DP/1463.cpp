#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cur;
    cin >> n;

    int *visit = new int[n + 1];
    fill_n(visit, n + 1, 0);

    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == 1)
            break;
        if (cur % 3 == 0)
        {
            int next = cur / 3;
            if (next > 0 & !visit[next])
            {
                visit[next] = visit[cur] + 1;
                q.push(next);
            }
        }
        if (cur % 2 == 0)
        {
            int next = cur / 2;
            if (next > 0 && !visit[next])
            {
                visit[next] = visit[cur] + 1;
                q.push(next);
            }
        }
        int next = cur - 1;
        if (next > 0 && !visit[next])
        {
            visit[next] = visit[cur] + 1;
            q.push(next);
        }
    }
    cout << visit[1];

    delete[] visit;
    return 0;
}
