#include <iostream>
using namespace std;
#include <vector>
#define maxn 100000
int d[maxn];

int main()
{
    int N, M;
    cin >> N >> M;
    int nearliest = 100000000;
    // 用 vector 存储最靠近M的不用考虑越界的问题
    vector<string> near;
    for (int i = 0; i < N; i++)
        cin >> d[i];
    int start = 0, end = 0, res = 0;
    int flag = 0; // flag == 0 表示还没找到等于M的序列
    while (start != N - 1)
    {
        if (res < M)
        {
            res += d[end];
            if (end < N)
                end++;
            continue;
        }
        else if (res == M)
        {
            cout << start + 1 << "-" << end << endl;
            flag = 1;
            res += d[end];
            if (end < N)
                end++;
        }
        else
        {
            if (flag == 0)
            {
                if (res < nearliest)
                {
                    nearliest = res;
                    vector<string>().swap(near);
                    near.push_back(to_string(start + 1) + "-" + to_string(end));
                }
                else if (res == nearliest)
                    near.push_back(to_string(start + 1) + "-" + to_string(end));
            }
            res -= d[start];
            start++;
        }
    }
    if (flag == 0)
        for (vector<string>::iterator it = near.begin(); it < near.end(); it++)
            cout << *it << endl;

    system("pause");
    return 0;
}