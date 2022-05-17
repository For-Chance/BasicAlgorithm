#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct node
{
    int addr;
    int value;
    int next;
};

bool cmp(node a, node b)
{
    return a.value < b.value;
}

int main()
{
    int N, s;
    cin >> N >> s;
    vector<node> d(N);
    for (int i = 0; i < N; i++)
        cin >> d[i].addr >> d[i].value >> d[i].next;
    sort(d.begin(), d.end(), cmp);
    if (N == 0 || s == -1)
        cout << 0 << " " << -1 << endl;
    else
    {
        printf("%d %05d\n", N, d[0].addr);
        int i;
        for (i = 0; i < N - 1; i++)
        {
            printf("%05d %d %05d\n", d[i].addr, d[i].value, d[i + 1].addr);
        }
        printf("%05d %d %d\n", d[i].addr, d[i].value, -1);
    }
    system("pause");
    return 0;
}