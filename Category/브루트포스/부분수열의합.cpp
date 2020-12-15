#include <iostream>

using namespace std;

int n, s;
int num[20];
int cnt;

void findSum(int index, int sum)
{
    if (index == n)
        return;
    if (sum + num[index] == s)
        cnt++;
    findSum(index + 1, sum + num[index]);
    findSum(index + 1, sum);
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> num[i];
}

int main()
{
    input();
    findSum(0, 0);
    cout << cnt << '\n';

    return 0;
}