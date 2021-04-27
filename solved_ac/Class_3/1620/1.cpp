#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
struct poketmon
{
    string name;
    int num;
};
vector<string> name_dict;
vector<poketmon> sorted_dict;
bool compare(poketmon a, poketmon b)
{
    return a.name < b.name;
}
int binarySearch(string a)
{
    int left = 0, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (sorted_dict[mid].name == a)
        {
            return sorted_dict[mid].num;
        }
        else if (sorted_dict[mid].name < a)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    // index와 포켓몬 번호 일치시키기 위해 0번 index 채우기
    name_dict.push_back("0");
    sorted_dict.push_back({"0", 0});
    for (int i = 1; i < n + 1; i++)
    {
        string s;
        cin >> s;
        name_dict.push_back(s);
        sorted_dict.push_back({s, i});
    }
    sort(sorted_dict.begin() + 1, sorted_dict.end(), compare);

    while (m--)
    {
        string problem;
        try
        {
            cin >> problem;
            if (!isalpha(problem[0]))
            {
                throw stoi(problem);
            }
            int ans = binarySearch(problem);
            cout << ans << '\n';
        }
        catch (int problem)
        {
            cout << name_dict[problem] << '\n';
        }
    }

    return 0;
}