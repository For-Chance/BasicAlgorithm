#include <iostream>
using namespace std;
#include <stack>
#include <string.h>
const int sqrN = 317;

stack<int> v;
int block[sqrN];   // 这里标号是 0-316，因此向下取整就行, 317 * 317 = 100489
int table[100490]; // 记录对应下标有几个数字

int main()
{
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));
    int N;
    cin >> N;
    string s;
    int a, K;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> a;
            v.push(a);
            block[a / sqrN]++;
            table[a]++;
        }
        else if (s[1] == 'o')
        {
            if (v.size() == 0)
                cout << "Invalid" << endl;
            else
            {
                a = v.top();
                cout << a << endl;
                v.pop();
                block[a / sqrN]--;
                table[a]--;
            }
        }
        else
        {
            K = v.size();
            if (K == 0)
            {
                cout << "Invalid" << endl;
                continue;
            }
            else if (K % 2 == 1)
                K = (K + 1) / 2;
            else
                K = K / 2;
            int idx = 0, num = 0, sum = 0; // 块号 和 最后的数字 和 第几大
            while (sum + block[idx] < K)
                sum += block[idx++];
            num = idx * sqrN; // 块内的第一个编号
            while (sum + table[num] < K)
                sum += table[num++];
            cout << num << endl;
        }
    }
    system("pause");
    return 0;
}