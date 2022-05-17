#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int lnum, rnum;
    long double sum = 0.0, a;
    for (int i = 1; i <= N; i++)
    {
        lnum = i;
        rnum = N - i + 1;
        cin >> a;
        sum += a * lnum * rnum;
    }
    printf("%.2Lf\n", sum);
    system("pause");
    return 0;
}