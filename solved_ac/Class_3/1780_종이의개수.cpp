#include <vector>
#include <iostream>

using namespace std;

int paper[2187][2187];
int ans[3];

void solve(int y, int x, int size)
{
    int std = paper[y][x];
    if (size == 1)
    {
        ans[std + 1]++;
        return;
    }
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (paper[i][j] != std)
            {
                for (int r = 0; r < 3; r++)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        solve(y + (size / 3) * r, x + (size / 3) * c, size / 3);
                    }
                }
                return;
            }
        }
    }
    ans[std + 1]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }
    solve(0, 0, n);
    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n';

    return 0;
}