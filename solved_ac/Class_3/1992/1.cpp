#include <iostream>

using namespace std;

int video[64][64];

void solve(int y, int x, int size)
{
    int check = video[y][x];
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (check != video[i][j])
            {
                cout << "(";
                solve(y, x, size / 2);
                solve(y, x + size / 2, size / 2);
                solve(y + size / 2, x, size / 2);
                solve(y + size / 2, x + size / 2, size / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << check;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    char a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            video[i][j] = a - '0';
        }
    }
    solve(0, 0, n);

    return 0;
}