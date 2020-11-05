#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    int year, month, day;
    char name[20];
};
int n;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
}

bool compare(student a, student b)
{
    if (a.year == b.year)
    {
        if (a.month == b.month)
        {
            return a.day < b.day;
        }
        return a.month < b.month;
    }
    return a.year < b.year;
}

void solve()
{
    vector<student> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].name >> v[i].day >> v[i].month >> v[i].year;
    sort(v.begin(), v.end(), compare);
    cout << v[n - 1].name << '\n'
         << v[0].name;
}

int main()
{
    input();
    solve();

    return 0;
}