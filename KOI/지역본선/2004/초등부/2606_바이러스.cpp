#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // 2차원 배열 동적 할당
    int **map = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        map[i] = new int[n + 1];
    }
    // 2차원 배열 0으로 초기화
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            map[i][j] = 0;
        }
    }
    // 서로 연결돼있으면 1로 할당
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }

    queue<int> Q;
    int cnt = 0;
    bool *ch = new bool[n + 1];
    fill_n(ch, n + 1, false);
    ch[1] = true;
    Q.push(1);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int i = 1; i < n + 1; i++)
        {
            if (map[cur][i] == 1 && !ch[i])
            {
                ch[i] = true;
                Q.push(i);
                cnt += 1;
            }
        }
    }
    printf("%d", cnt);
    // 동적 메모리 해제
    for (int i = 0; i < n + 1; i++)
    {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}