#include <iostream>
#include <algorithm>
using namespace std;

void printRes(int *arr)
{
    for (int i = 2; i < 9; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{
    int tall[9];
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &tall[i]);
        sum += tall[i];
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - tall[i] - tall[j] == 100)
            {
                tall[i] = 0;
                tall[j] = 0;
                sort(tall, tall + 9);
                printRes(tall);
                return 0;
            }
        }
    }
}