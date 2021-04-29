#include <iostream>

using namespace std;

int N, M;
int made[8];

void printSeries(int L, int start)
{
    if (L == M)
    {
        for (int i = 0; i < M; i++)
            cout << made[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i <= N; i++)
    {
        made[L] = i;
        printSeries(L + 1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    printSeries(0, 1);
    return 0;
}