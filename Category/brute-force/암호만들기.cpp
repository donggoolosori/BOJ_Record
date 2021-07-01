#include <iostream>
#include <algorithm>

using namespace std;

int len, kind;
char useableAlp[15];

bool isValidSecret(string made)
{
    if (made.length() != len)
        return false;
    int consonant = 0, vowel = 0;
    for (int i = 0; i < made.length(); i++)
    {
        if (made[i] == 'a' || made[i] == 'e' || made[i] == 'i' || made[i] == 'o' || made[i] == 'u')
            vowel++;
        else
            consonant++;
    }
    if (vowel < 1 || consonant < 2)
        return false;
    return true;
}

void findSecret(int index, string made)
{
    if (index == kind)
    {
        if (isValidSecret(made))
            cout << made << '\n';
        return;
    }
    findSecret(index + 1, made + useableAlp[index]);
    findSecret(index + 1, made);
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> len >> kind;
    for (int i = 0; i < kind; i++)
        cin >> useableAlp[i];
}

int main()
{
    input();
    sort(useableAlp, useableAlp + kind);
    findSecret(0, "");

    return 0;
}