#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int idx = 0;
    string stand = "UCPC";
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (stand[idx] == s[i])
        {
            idx++;
            if (idx == 4)
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";

    return 0;
}