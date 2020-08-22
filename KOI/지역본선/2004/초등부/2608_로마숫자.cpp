#include <iostream>
#include <string>

using namespace std;

const string symbol = "IVXLCDM";
const int val[] = {1, 5, 10, 50, 100, 500, 1000};
const string complexSymbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const int complexVal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

int getMatchedVal(const char c)
{
    for (int i = 0; i < 7; i++)
    {
        if (symbol[i] == c)
            return val[i];
    }
    return -1;
}
int romeToArab(string a)
{
    int res = 0;
    for (int i = 0; a[i]; i++)
    {
        if (getMatchedVal(a[i]) < getMatchedVal(a[i + 1]))
            res -= getMatchedVal(a[i]);
        else
            res += getMatchedVal(a[i]);
    }
    return res;
}
string arabToRome(int arabian)
{
    string s = "";
    while (arabian)
    {
        for (int i = 0; i < 13; i++)
        {
            if (complexVal[i] <= arabian)
            {
                arabian -= complexVal[i];
                s += complexSymbol[i];
                break;
            }
        }
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arabian = 0;
    string a, b;
    cin >> a >> b;
    arabian = romeToArab(a) + romeToArab(b);
    string rome = arabToRome(arabian);
    cout << arabian << "\n"
         << rome;

    return 0;
}