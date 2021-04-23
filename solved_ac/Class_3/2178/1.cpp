#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<string> maze(100);
vector<vector<int>> visit(100, vector<int>(100));
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
struct Node
{
    int y, x, move;
};

int getMinPath()
{
    queue<Node> q;
    q.push({0, 0, 1});
    visit[0][0] = true;

    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();
        visit[curr.y][curr.x] = true;

        if (curr.y == N - 1 && curr.x == M - 1)
            return curr.move;

        for (int i = 0; i < 4; i++)
        {
            int ny = curr.y + dy[i], nx = curr.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M || maze[ny][nx] == '0' || visit[ny][nx])
                continue;
            visit[ny][nx] = true;
            q.push({ny, nx, curr.move + 1});
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
    for (int i = 0; i < N; i++)
        cin >> maze[i];

    cout << getMinPath() << '\n';

    return 0;
}