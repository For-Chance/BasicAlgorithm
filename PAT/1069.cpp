#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

void calBlack(string N)
{
    int N_size = N.size();
    if (N_size != 4)
    {
        string x0 = "";
        x0.assign(4 - N_size, '0');
        N.append(x0);
    }
    sort(N.begin(), N.end());
    string M = N;
    reverse(M.begin(), M.end());
    int Nnum = stoi(N);
    int Mnum = stoi(M);
    int black = Mnum - Nnum;
    printf("%04d - %04d = %04d\n", Mnum, Nnum, black);
    if (!(Mnum == Nnum || black == 6174))
        calBlack(to_string(black));
}

int main()
{
    string N;
    cin >> N;
    calBlack(N);

    system("pause");
    return 0;
}