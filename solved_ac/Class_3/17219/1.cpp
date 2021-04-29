#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> memo;

    string site, pw;
    while (N--)
    {
        cin >> site >> pw;
        memo[site] = pw;
    }
    while (M--)
    {
        cin >> site;
        cout << memo[site] << '\n';
    }

    return 0;
}