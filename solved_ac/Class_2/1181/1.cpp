#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> vec;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        vec.push_back(s);
    }
}

bool compare(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main()
{
    input();
    sort(vec.begin(), vec.end(), compare);
    string prev = "";
    for (const auto &s : vec)
    {
        if (s == prev)
            continue;
        prev = s;
        cout << s << '\n';
    }

    return 0;
}