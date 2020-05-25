#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        if (n > max)
        {
            max = n;
        }
        if (n < min)
        {
            min = n;
        }
    }
    printf("%d %d", min, max);
    return 0;
}