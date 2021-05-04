#include <stdio.h>
#include <vector>

using namespace std;

const int ROW = 3072, COL = 6144;
vector<vector<char>> stars(ROW, vector<char>(COL, ' '));
int N;

void makeStars(int size, int y, int x)
{
    if (size == 3)
    {
        stars[y][x] = '*';
        stars[y + 1][x + 1] = '*';
        stars[y + 1][x - 1] = '*';
        for (int i = -2; i < 3; i++)
            stars[y + 2][x + i] = '*';
        return;
    }
    makeStars(size / 2, y, x);
    makeStars(size / 2, y + size / 2, x - size / 2);
    makeStars(size / 2, y + size / 2, x + size / 2);
}

void printStars()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
            printf("%c", stars[i][j]);
        printf("\n");
    }
}

int main()
{
    scanf("%d", &N);

    makeStars(N, 0, N - 1);
    printStars();

    return 0;
}