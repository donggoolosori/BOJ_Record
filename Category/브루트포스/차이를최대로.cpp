#include <vector>
#include <iostream>
#define max(a, b) a > b ? a : b
using namespace std;

int n;
int arr[8];
bool visit[8];
int ans;

int calculate(vector<int> made)
{
    int ret = 0;
    int l = made.size();
    for (int i = 0; i < l - 1; i++)
        ret += abs(made[i] - made[i + 1]);
    return ret;
}

void setArr(vector<int> made)
{
    if (made.size() == n)
    {
        ans = max(ans, calculate(made));
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            made.push_back(arr[i]);
            setArr(made);
            made.pop_back();
            visit[i] = false;
        }
    }
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int main()
{
    input();
    vector<int> v;
    setArr(v);

    cout << ans << '\n';

    return 0;
}