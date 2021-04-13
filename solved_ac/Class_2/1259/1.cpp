#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s_num;
    while (true)
    {
        cin >> s_num;
        if (s_num == "0")
            break;
        if (s_num.length() == 1)
        {
            cout << "yes" << '\n';
            continue;
        }
        for (int i = 0; i < s_num.length() / 2; i++)
        {
            if (s_num[i] != s_num[s_num.length() - i - 1])
            {
                cout << "no" << '\n';
                break;
            }
            if (i == s_num.length() / 2 - 1)
            {
                cout << "yes" << '\n';
            }
        }
    }
}