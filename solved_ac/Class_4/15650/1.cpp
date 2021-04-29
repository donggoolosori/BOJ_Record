#include <iostream>

using namespace std;

int N, M;
int made[8];

void printComb(int L, int S)
{
    if (L == M)
    {
        for (int i = 0; i < M; i++)
            cout << made[i] << ' ';
        cout << '\n';
    }

    for (int i = S; i <= N; i++)
    {
        made[L] = i;
        printComb(L + 1, i + 1);
        made[L] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    printComb(0, 1);

    return 0;
}