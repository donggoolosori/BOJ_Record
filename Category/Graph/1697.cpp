#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001
int n, k;
vector<int> visit(MAX, 0);
queue<int> q;

void checkNext(int cur, int next)
{
    if ((0 <= next) && (next < MAX) && (visit[next] == 0 || visit[next] > visit[cur] + 1))
    {
        visit[next] = visit[cur] + 1;
        q.push(next);
    }
}
void bfs()
{
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == k)
        {
            cout << visit[cur];
            break;
        }
        checkNext(cur, cur + 1);
        checkNext(cur, cur * 2);
        checkNext(cur, cur - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    if (n >= k)
        cout << n - k;
    else
    {
        q.push(n);
        bfs();
    }

    return 0;
}