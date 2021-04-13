#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(int num)
{
    string s = to_string(num);
    string a, b;
    int len = s.length();
    a = s.substr(0, len / 2);
    if (len % 2 == 0)
        b = s.substr(len / 2);
    else
        b = s.substr(len / 2 + 1);
    reverse(b.begin(), b.end());

    if (a == b)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    while (true)
    {
        cin >> num;
        if (num == 0)
            break;

        if (isPalindrome(num))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}