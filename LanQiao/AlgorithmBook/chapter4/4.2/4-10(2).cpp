#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[105], b[105];
    while (cin >> a >> b)
    {
        int a1[105] = {0}, b1[105] = {0};
        int len1 = strlen(a), len2 = strlen(b); //长度
        for (int i = 'A'; i <= 'Z'; i++)
        {
            int num = count(a, a + len1, (char)i);
            (num == 0) ?: a1[num]++;
            num = count(b, b + len2, (char)i);
            (num == 0) ?: b1[num]++;
        }
        cout << ((memcmp(a1, b1, sizeof(a1))) ? "NO" : "YES") << endl;
    }
    return 0;
}
