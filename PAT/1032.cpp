#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct node
{
    char n;
    int back;
} l[100000];

string getword(int s)
{
    int addr = s;
    string a = "";
    while (l[addr].back != -1)
    {
        a += l[addr].n;
        addr = l[addr].back;
    }
    a += l[addr].n;
    return a;
}

int main()
{
    int s1, s2, N;
    cin >> s1 >> s2 >> N;
    int address;
    for (int i = 0; i < N; i++)
    {
        cin >> address;
        cin >> l[address].n >> l[address].back;
    }
    string w1 = getword(s1);
    string w2 = getword(s2);
    reverse(w1.begin(), w1.end());
    reverse(w2.begin(), w2.end());
    int i = 0;
    for (; i < w1.length(); i++)
        if (w1[i] != w2[i])
            break;
    if (i == 0)
        cout << -1 << endl;
    else
    {
        int index = w1.length() - i; // 标识了w1的第几个单词是sharing的开头
        int addr = s1, j;
        for (j = 0; j < index; j++)
            addr = l[addr].back;
        printf("%05d\n", addr);
    }
    system("pause");
    return 0;
}