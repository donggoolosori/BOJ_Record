#include <iostream>
#include <queue>

using namespace std;

int N, M;
int board[101];
bool visit[101];
struct Pos
{
    int idx, move;
};

int getMinDice()
{
    queue<Pos> q;
    q.push({1, 0});
    visit[1] = true;

    while (!q.empty())
    {
        Pos curr = q.front();
        q.pop();

        if (curr.idx == 100)
            return curr.move;

        for (int i = 1; i <= 6; i++)
        {
            int next = curr.idx + i;
            if (next > 100)
                continue;
            if (board[next] != 0)
                next = board[next];
            if (!visit[next])
            {
                visit[next] = true;
                q.push({next, curr.move + 1});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    while (N--)
    {
        cin >> a >> b;
        board[a] = b;
    }
    while (M--)
    {
        cin >> a >> b;
        board[a] = b;
    }

    cout << getMinDice() << '\n';

    return 0;
}