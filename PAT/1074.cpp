#include <iostream>
using namespace std;
#include <algorithm>
int K, ct = 0;

struct node
{
    int address;
    int value;
    int next;
    bool flag;
    int rank;
} l[100000];

// 如果 a 或者 b 中的 flag 有false的，就把false的移到后面
bool cmp(node a, node b)
{
    if (!a.flag || !b.flag)
        return a.flag > b.flag;
    else
    {
        if ((a.rank / K) == (b.rank / K))
            if ((a.rank / K) == ct / K)
                return a.rank < b.rank;
            else
                return a.rank > b.rank;
        else
            return (a.rank / K) < (b.rank / K);
    }
    return a.rank < b.rank;
}

int main()
{
    int s, N;
    cin >> s >> N >> K;
    int addr;
    for (int i = 0; i < N; i++)
    {
        cin >> addr;
        l[addr].address = addr;
        cin >> l[addr].value >> l[addr].next;
        l[addr].flag = false;
    }
    int a = 0;
    for (int i = s; i != -1; i = l[i].next)
    {
        l[i].flag = true;
        l[i].rank = a++;
        ct++;
    }
    sort(l, l + 100000, cmp);
    int i;
    for (i = 0; i < ct - 1; i++)
        printf("%05d %d %05d\n", l[i].address, l[i].value, l[i + 1].address);
    printf("%05d %d %d\n", l[i].address, l[i].value, -1);
    system("pause");
    return 0;
}