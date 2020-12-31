#include <iostream>
#include <algorithm>

using namespace std;

int n;
int wTime[1000];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> wTime[i];
}

int main()
{
    input();
    sort(wTime, wTime + n);
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += wTime[i];
        ans += sum;
    }

    cout << ans << '\n';
    return 0;
}