#include <iostream>

using namespace std;

int n;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
}

int main()
{
    input();

    int cnt = 0;
    int num = 666;
    while (true)
    {
        string s = to_string(num++);

        if (s.find("666") != -1)
            cnt++;
        if (cnt == n)
        {
            cout << s << '\n';
            break;
        }
    }
    return 0;
}