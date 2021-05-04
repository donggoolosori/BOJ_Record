#include <iostream>
#include <algorithm>

using namespace std;

int numbers[8], made[8], visit[8];
int N, M;

void printPermutations(int L)
{
    if (L == M)
    {
        for (int i = 0; i < M; i++)
            cout << made[i] << ' ';
        cout << '\n';
    }
    for (int i = 0; i < N; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        made[L] = numbers[i];
        printPermutations(L + 1);
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

    printPermutations(0);

    return 0;
}