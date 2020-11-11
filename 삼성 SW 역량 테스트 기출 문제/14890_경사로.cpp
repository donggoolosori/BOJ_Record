#include <iostream>
#include <vector>

using namespace std;

int n, l;
int map[100][100];
int ans;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
}

void checkRows()
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        vector<bool> check(n, 0);

        for (int j = 1; j < n; j++)
        {
            // 차이가 2이상이면 길 x
            if (abs(map[i][j] - map[i][j - 1]) >= 2)
            {
                flag = false;
                break;
            }

            // 현재 숫자가 뒤의 수보다 1 클 경우
            if (map[i][j] > map[i][j - 1])
            {
                // 경사로가 범위를 넘어갈 경우 길 x
                if (j - l < 0)
                {
                    flag = false;
                    break;
                }
                int std = map[i][j - 1];
                for (int k = j - 1; k >= j - l; k--)
                {
                    // 경사로를 놓는 부분이 평지가 아니거나
                    // 이미 경사로가 놓아져 있다면 길 x
                    if (map[i][k] != std || check[k])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
                else
                {
                    // 경사로 check
                    for (int k = j - 1; k >= j - l; k--)
                    {
                        check[k] = true;
                    }
                }
            }

            // 현재 숫자가 뒤의 숫자보다 1 작을 경우
            if (map[i][j] < map[i][j - 1])
            {
                // 경사로가 범위를 넘어갈 경우 길 x
                if (j + l - 1 >= n)
                {
                    flag = false;
                    break;
                }
                int std = map[i][j];
                for (int k = j; k < j + l; k++)
                {
                    // 경사로를 놓는 부분이 평지가 아니거나
                    // 이미 경사로가 놓아져 있다면
                    if (map[i][k] != std || check[k])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
                else
                {
                    for (int k = j; k < j + l; k++)
                    {
                        check[k] = true;
                    }
                    j += (l - 1);
                }
            }
        }
        if (!flag)
        {
            ans--;
        }
    }
}

void checkColumns()
{
    for (int j = 0; j < n; j++)
    {
        bool flag = true;
        vector<bool> check(n, 0);

        for (int i = 1; i < n; i++)
        {
            // 차이가 2이상이면 길 x
            if (abs(map[i][j] - map[i - 1][j]) >= 2)
            {
                flag = false;
                break;
            }

            // 현재 숫자가 뒤의 수보다 1 클 경우
            if (map[i][j] > map[i - 1][j])
            {
                // 경사로가 범위를 넘어갈 경우 길 x
                if (i - l < 0)
                {
                    flag = false;
                    break;
                }
                int std = map[i - 1][j];
                for (int k = i - 1; k >= i - l; k--)
                {
                    // 경사로를 놓는 부분이 평지가 아니거나
                    // 이미 경사로가 놓아져 있다면 길 x
                    if (map[k][j] != std || check[k])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
                else
                {
                    // 경사로 check
                    for (int k = i - 1; k >= i - l; k--)
                    {
                        check[k] = true;
                    }
                }
            }

            // 현재 숫자가 뒤의 숫자보다 1 작을 경우
            if (map[i][j] < map[i - 1][j])
            {
                // 경사로가 범위를 넘어갈 경우 길 x
                if (i + l - 1 >= n)
                {
                    flag = false;
                    break;
                }
                int std = map[i][j];
                for (int k = i; k < i + l; k++)
                {
                    // 경사로를 놓는 부분이 평지가 아니거나
                    // 이미 경사로가 놓아져 있다면
                    if (map[k][j] != std || check[k])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
                else
                {
                    for (int k = i; k < i + l; k++)
                    {
                        check[k] = true;
                    }
                    i += (l - 1);
                }
            }
        }
        if (!flag)
        {
            ans--;
        }
    }
}

void solve()
{
    checkRows();
    checkColumns();
    ans += 2 * n;
    cout << ans << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}