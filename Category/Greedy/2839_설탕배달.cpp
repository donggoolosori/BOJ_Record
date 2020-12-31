#include <iostream>

using namespace std;

int N;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
}

int main()
{
    input();

    int ans = -1;
    int remain;
    for (int i = N / 5; i >= 0; i--)
    {
        remain = N - i * 5;
        if (remain % 3 == 0)
        {
            ans = i + remain / 3;
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}