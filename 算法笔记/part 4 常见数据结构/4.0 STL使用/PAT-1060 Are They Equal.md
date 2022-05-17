# 1060 Are They Equal

> part 4, 4.0



## 自己解法

- 最后一个和倒数第三个WA
- 感觉还是要先把思路和边界想清楚再写代码，不然就会写得特别乱

```c++
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int N;

void pluszero(string &a)
{
    int x = a.length();
    if (x < N)
        for (int i = 0; i < (N - x); i++)
            a.append("0");
}

int getk(string &a)
{
    int pos = a.find('.');
    if (pos == string::npos)
    {
        int x = a.length();
        pluszero(a);
        return x;
    }
    else
    {
        if (a[0] == '0' && a[1] == '.')
        {
            int count0 = 0;
            for (int i = 2;; i++)
                if (a[i] != '0')
                    break;
                else
                    count0++;
            if (count0 != a.length() - 2)
            {
                a = a.substr(2 + count0);
                pluszero(a);
            }
            else // 相当于为0.0000
            {
                a = a.substr(2);
                pluszero(a);
                return 0;
            }
            return -count0;
        }
        else
        {
            string s1 = a.substr(0, pos);
            s1.append(a.substr(pos + 1));
            a = s1;
            pluszero(a);
            return pos;
        }
    }
}

int main()
{
    cin >> N;
    string A, B;
    cin >> A >> B;
    int k1, k2;
    k1 = getk(A);
    k2 = getk(B);
    int flag = 1;
    if (k1 == k2)
    {
        for (int i = 0; i < N; i++)
        {
            if (A[i] == B[i])
                continue;
            else if (A[i] != B[i])
            {
                flag = 0;
                cout << "NO"
                     << " "
                     << "0." << A.substr(0, N) << "*10^" << k1 << " "
                     << "0." << B.substr(0, N) << "*10^" << k2 << endl;
                break;
            }
        }
        if (flag == 1)
            cout << "YES"
                 << " "
                 << "0." << A.substr(0, N) << "*10^" << k1 << endl;
    }
    else
    {
        cout << "NO"
             << " "
             << "0." << A.substr(0, N) << "*10^" << k1 << " "
             << "0." << B.substr(0, N) << "*10^" << k2 << endl;
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n, p = 0, q = 0;
    char a[10000], b[10000], A[10000], B[10000];
    scanf("%d%s%s", &n, a, b);
    int cnta = strlen(a), cntb = strlen(b);
    for(int i = 0; i < strlen(a); i++) {
        if(a[i] == '.') {
            cnta = i;
            break;
        }
    }
    for(int i = 0; i < strlen(b); i++) {
        if(b[i] == '.') {
            cntb = i;
            break;
        }
    }
    int indexa = 0, indexb = 0;
    while(a[p] == '0' || a[p] == '.') p++;
    while(b[q] == '0' || b[q] == '.') q++;
    if(cnta >= p) // 小数点的位置大于有效数字的开头
        cnta = cnta - p; // k
    else
        cnta = cnta - p + 1;
    if(cntb >= q)
        cntb = cntb - q;
    else
        cntb = cntb - q + 1;
    if(p == strlen(a)) // 相当于全为0的时候
        cnta = 0;
    if(q == strlen(b))
        cntb = 0;
    while(indexa < n) {
        if(a[p] != '.' && p < strlen(a))
            A[indexa++] = a[p];
        else if(p >= strlen(a))
            A[indexa++] = '0';
        p++;
    }
    while(indexb < n) {
        if(b[q] != '.' && q < strlen(b))
            B[indexb++] = b[q];
        else if(q >= strlen(b))
            B[indexb++] = '0';
        q++;
    }
    if(strcmp(A, B) == 0 && cnta == cntb)
        printf("YES 0.%s*10^%d", A, cnta);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d" , A, cnta, B, cntb);
    return 0;
}
```

