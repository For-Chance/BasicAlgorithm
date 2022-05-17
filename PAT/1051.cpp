#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int flag = 1, c;
        stack<int> s;
        vector<int> order(N + 1);
        for (int j = 1; j <= N; j++)
            cin >> order[j];
        int now = 1;
        for (int j = 1; j <= N; j++)
        {
            s.push(j);
            if (s.size() > M)
            {
                flag = 0;
                break;
            }
            while (s.size() != 0 && s.top() == order[now])
            {
                s.pop();
                now++;
            }
        }
        if (now != N + 1)
            flag = 0;
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}