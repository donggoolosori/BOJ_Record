#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string seat;
    cin >> seat;

    int cnt = 1;
    for (int i = 0; i < seat.length(); i++)
    {
        if (seat[i] == 'L')
        {
            cnt++;
            i++;
        }
        else
        {
            cnt++;
        }
    }
    cnt = cnt > n ? n : cnt;
    cout << cnt;
    return 0;
}