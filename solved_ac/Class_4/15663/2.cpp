#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int numbers[8], visit[8], made[8];

void printPermut(int L)
{
    if (L == M)
    {
        for (int i = 0; i < M; i++)
            cout << made[i] << ' ';
        cout << '\n';
        return;
    }

    int before = 0;
    for (int i = 0; i < N; i++)
    {
        if (visit[i] || before == numbers[i])
            continue;
        before = numbers[i];
        visit[i] = true;
        made[L] = numbers[i];
        printPermut(L + 1);
        visit[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    sort(numbers, numbers + N);

    printPermut(0);

    return 0;
}