#include <iostream>
#include <string>
using namespace std;

class ApoNum
{
private:
    int seriesNum;
    int ApNum;

public:
    ApoNum(int n)
        : seriesNum(n), ApNum(0)
    {
    }
    int CalApNum()
    {
        ApNum = 665;
        int i = 0;
        while (i < seriesNum)
        {
            ApNum++;
            string s = to_string(ApNum);
            if (s.find("666") != -1) //including 666
            {
                i++;
            }
        }
        return ApNum;
    }
};

int main()
{
    int N;
    cin >> N;
    ApoNum ap(N);
    cout << ap.CalApNum() << endl;
    return 0;
}