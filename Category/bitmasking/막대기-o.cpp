#include <iostream>

using namespace std;

int x, answer;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;
}

int main()
{
    input();

    for (int i = 0; i < 7; i++)
    {
        if (x & (1 << i))
            answer++;
    }
    cout << answer << '\n';
    return 0;
}