#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> paper(101, vector<int>(101, 0));
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (int i = a + 1; i < a + 11; i++)
        {
            for (int j = b + 1; j < b + 11; j++)
            {
                paper[i][j] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            sum += paper[i][j];
        }
    }
    cout << sum;

    return 0;
}