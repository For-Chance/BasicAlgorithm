#include <iostream>
using namespace std;
#include <vector>
#include <string.h>

int main()
{
    int N;
    cin >> N;
    int d[10001];
    memset(d, 0, 10001);
    vector<int> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
        d[s[i]]++;
    }
    int j;
    for (j = 0; j < N; j++)
        if (d[s[j]] == 1)
            break;
    if (j == N)
        cout << "None" << endl;
    else
        cout << s[j] << endl;

    system("pause");
    return 0;
}