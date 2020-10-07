#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> map;
    string s1, s2;
    while (n--)
    {
        cin >> s1 >> s2;
        map.insert({s1, s2});
    }
    string s3;
    while (m--)
    {
        cin >> s3;
        cout << map[s3] << '\n';
    }
    return 0;
}