#include <iostream>

using namespace std;

int n;
char arr[3072][6144];

void initialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < 3072; i++)
    {
        for (int j = 0; j < 6144; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

void setStar(int size, int y, int x)
{
    if (size == 3)
    {
        arr[y][x] = '*';

        arr[y + 1][x - 1] = '*';
        arr[y + 1][x + 1] = '*';

        for (int i = 0; i < 5; i++)
            arr[y + 2][x - 2 + i] = '*';
    }
    else
    {
        setStar(size / 2, y, x);
        setStar(size / 2, y + size / 2, x - size / 2);
        setStar(size / 2, y + size / 2, x + size / 2);
    }
}

void printStar()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}
int main()
{
    initialize();
    setStar(n, 0, n - 1);
    printStar();

    return 0;
}