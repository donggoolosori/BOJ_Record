#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    vector<string> B(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    int cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            if (A[i][j] != B[i][j])
            {
                cnt++;
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        if (A[k][l] == '0')
                            A[k][l] = '1';
                        else
                            A[k][l] = '0';
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            cout << -1;
            return 0;
        }
    }
    cout << cnt;

    return 0;
}