#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

char sName[40010][5];

bool cmp(int a, int b)
{
    return strcmp(sName[a], sName[b]) < 0;
}

int main()
{
    int N, K;
    cin >> N >> K;
    map<int, vector<int>> m;
    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%s %d\n", &sName[i], &k);
        int index;
        for (int j = 0; j < k; j++)
        {
            cin >> index;
            m[index].push_back(i);
        }
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second.size() << endl;
        sort(it->second.begin(), it->second.end(), cmp);
        for (int i = 0; i < it->second.size(); i++)
            printf("%s\n", sName[it->second[i]]);
    }
    system("pause");
    return 0;
}