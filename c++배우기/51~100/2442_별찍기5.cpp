#include <iostream>
#include <iomanip>

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
    for (int i = 1; i <= n; i++)
    {
        cout << setw(n - i + 1);
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << '\n';
    }
    return 0;
}