#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bitset<21> bit;
    bit.reset();
    string op;
    int m, val;
    cin >> m;

    while (m--)
    {
        cin >> op;
        if (op != "all" && op != "empty")
            cin >> val;

        if (op == "add")
            bit.set(val, 1);
        else if (op == "remove")
            bit.set(val, 0);
        else if (op == "check")
        {
            if (bit[val])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (op == "toggle")
            bit.flip(val);
        else if (op == "all")
            bit.set();
        else if (op == "empty")
            bit.reset();
    }

    return 0;
}