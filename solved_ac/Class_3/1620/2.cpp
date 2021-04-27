#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int N, M;
string keyIsNum[100001];
unordered_map<string, int> keyIsName;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string a;
    for (int i = 1; i <= N; i++)
    {
        cin >> a;
        keyIsNum[i] = a;
        keyIsName[a] = i;
    }
    while (M--)
    {
        cin >> a;
        if (isdigit(a[0]))
            cout << keyIsNum[stoi(a)] << '\n';
        else
            cout << keyIsName[a] << '\n';
    }

    return 0;
}