#include <iostream>

using namespace std;

int N;
int row[15];
int cnt;

bool check(int r)
{
    for (int i = 0; i < r; i++)
        if (row[i] == row[r] || abs(row[i] - row[r]) == r - i)
            return false;
    return true;
}

void nQueen(int r)
{
    if (r == N)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        row[r] = i;
        if (check(r))
            nQueen(r + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nQueen(0);
    cout << cnt << '\n';
    return 0;
}