#include <iostream>
using namespace std;
#define n 54

int order[n] = {0};
int a[n] = {0};
int b[n] = {0};

void func()
{
    for (int i = 0; i < n; i++)
        a[order[i] - 1] = b[i];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

int main()
{
    string repCards[n] = {""};
    string repLetter[5] = {"S", "H", "C", "D"};
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= 13; j++)
        {
            int pos = i * 13 + j - 1;
            repCards[pos] = repLetter[i] + to_string(j);
        }
    repCards[52] = "J1";
    repCards[53] = "J2";

    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
        a[i] = i;
        b[i] = i;
    }

    for (int i = 0; i < k; i++)
        func();
    cout << repCards[a[0]];
    for (int i = 1; i < n; i++)
        cout << " " << repCards[a[i]];
    cout << endl;
    system("pause");
    return 0;
}