#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int total, start, goal, up, down;
vector<int> visit(1000001, 0);
queue<int> q;

void checkNext(int cur, int next)
{
    if ((next != start) && (0 < next && next < total + 1) && (!visit[next] || visit[next] > visit[cur] + 1))
    {
        visit[next] = visit[cur] + 1;
        q.push(next);
    }
}
void bfs()
{
    int cur;
    q.push(start);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == goal)
        {
            break;
        }
        checkNext(cur, cur + up);
        checkNext(cur, cur - down);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> total >> start >> goal >> up >> down;
    bfs();
    if (start == goal)
    {
        cout << 0;
        return 0;
    }
    if (visit[goal] == 0)
        cout << "use the stairs";
    else
        cout << visit[goal];
    return 0;
}
