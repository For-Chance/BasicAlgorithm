#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    int N, M;
    cin >> N;
    vector<map<int, int>> n(N); // map的集合
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        map<int, int> m;
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            map<int, int>::iterator pos = m.find(x);
            if (pos == m.end())
                m.insert(make_pair(x, 1));
            else
                pos->second++;
        }
        n[i] = m;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        int count = 0;
        map<int, int> m = n[a - 1];
        for (map<int, int>::iterator it = n[b - 1].begin(); it != n[b - 1].end(); it++)
        {
            map<int, int>::iterator pos = m.find(it->first);
            if (pos == m.end())
                m.insert(make_pair(it->first, 1)); // 找不到是0
            else
            {
                pos->second = 0; // 找得到就是0
                count++;
            }
        }
        double rate = double(count) / m.size() * 100;
        printf("%.1f%\n", rate);
    }
    system("pause");
    return 0;
}