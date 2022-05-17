#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int x, N;
int t[1000], s[1000];

void inOrder(int root)
{
    if (root >= N)
        return;
    inOrder(2 * root + 1);
    s[root] = t[x++];
    inOrder(2 * root + 2);
}

int main()
{
    x = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> t[i];
    sort(t, t + N);
    inOrder(0);
    for (int i = 0; i < N; i++)
        if (i != 0)
            cout << " " << s[i];
        else
            cout << s[i];
    cout << endl;
    system("pause");
    return 0;
}