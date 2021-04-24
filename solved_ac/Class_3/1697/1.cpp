#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;
int N, K;
bool visit[MAX + 1];
struct Node
{
    int idx, dist;
};

bool checkNext(int next)
{
    if (next < 0 || next > MAX || visit[next])
        return false;

    visit[next] = true;
    return true;
}

int getMinTime()
{
    queue<Node> q;
    q.push({N, 0});

    while (!q.empty())
    {
        Node curr = q.front();
        int idx = curr.idx, dist = curr.dist;
        q.pop();

        if (curr.idx == K)
            return curr.dist;

        if (checkNext(idx * 2))
            q.push({idx * 2, dist + 1});
        if (checkNext(idx + 1))
            q.push({idx + 1, dist + 1});
        if (checkNext(idx - 1))
            q.push({idx - 1, dist + 1});
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (N >= K)
        cout << N - K << '\n';
    else
        cout << getMinTime() << '\n';

    return 0;
}