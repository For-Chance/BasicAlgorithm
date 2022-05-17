#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int Nc, Np;
vector<int> NcP, NcN, NpP, NpN; // 分别代表两列的正数、负数

bool cmp(int a, int b)
{
    return abs(a) > abs(b);
}

int main()
{
    cin >> Nc;
    int a;
    for (int i = 0; i < Nc; i++)
    {
        cin >> a;
        if (a >= 0)
            NcP.push_back(a);
        else
            NcN.push_back(a);
    }
    cin >> Np;
    for (int i = 0; i < Np; i++)
    {
        cin >> a;
        if (a >= 0)
            NpP.push_back(a);
        else
            NpN.push_back(a);
    }
    sort(NcN.begin(), NcN.end(), cmp);
    sort(NcP.begin(), NcP.end(), cmp);
    sort(NpP.begin(), NpP.end(), cmp);
    sort(NpN.begin(), NpN.end(), cmp);
    int money = 0;
    for (int i = 0; i < NcN.size() && i < NpN.size(); i++)
        money += NcN[i] * NpN[i];
    for (int i = 0; i < NpP.size() && i < NcP.size(); i++)
        money += NpP[i] * NcP[i];
    cout << money << endl;
    system("pause");
    return 0;
}