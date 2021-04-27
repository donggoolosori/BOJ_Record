#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool visit[10000];
struct Node
{
    int num;
    string operation;
};

void getMinOp(int fr, int to)
{
    queue<Node> q;
    q.push({fr, ""});

    while (!q.empty())
    {
        Node curr = q.front();
        int num = curr.num;
        string operation = curr.operation;
        q.pop();

        if (num == to)
        {
            cout << operation << '\n';
            return;
        }

        int D, S, L, R;
        // D연산
        D = (num * 2) % 10000;
        if (!visit[D])
        {
            visit[D] = true;
            q.push({D, operation + "D"});
        }
        // S연산
        S = (num - 1 < 0) ? 9999 : num - 1;
        if (!visit[S])
        {
            visit[S] = true;
            q.push({S, operation + "S"});
        }
        // L연산
        L = (num % 1000) * 10 + (num / 1000);
        if (!visit[L])
        {
            visit[L] = true;
            q.push({L, operation + "L"});
        }
        // R연산
        R = (num % 10) * 1000 + (num / 10);
        if (!visit[R])
        {
            visit[R] = true;
            q.push({R, operation + "R"});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int fr, to;
    while (T--)
    {
        cin >> fr >> to;
        getMinOp(fr, to);
        memset(visit, 0, sizeof(visit));
    }

    return 0;
}