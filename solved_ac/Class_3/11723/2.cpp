#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, num, bit = 0;
    string op;
    cin >> M;
    while (M--)
    {
        cin >> op;
        if (op != "all" && op != "empty")
            cin >> num;

        if (op == "add")
            bit |= (1 << num);
        else if (op == "remove")
            bit &= ~(1 << num);
        else if (op == "check")
        {
            if (bit & (1 << num))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (op == "toggle")
            bit ^= (1 << num);
        else if (op == "all")
            bit = (1 << 21) - 1;
        else if (op == "empty")
            bit = 0;
    }

    return 0;
}