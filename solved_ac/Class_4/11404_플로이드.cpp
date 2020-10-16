#include <iostream>
#include <vector>

#define min(a, b) a < b ? a : b
#define INF 987654321

using namespace std;

int city[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            city[i][j] = INF;
        }
    }
    int fr, to, pr;
    while (m--)
    {
        cin >> fr >> to >> pr;
        if (city[fr][to] > pr)
            city[fr][to] = pr;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j || j == k || i == k)
                    continue;
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << city[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}