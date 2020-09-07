#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[3][4];
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
            temp += arr[i][j];
        }
        if (temp == 0)
            cout << "D" << '\n';
        else if (temp == 1)
            cout << "C" << '\n';
        else if (temp == 2)
            cout << "B" << '\n';
        else if (temp == 3)
            cout << "A" << '\n';
        else
            cout << "E" << '\n';
    }
    return 0;
}