#include <iostream>
using namespace std;
#include <set>
#include <map>
#include <vector>

int main()
{
    int N;
    cin >> N;
    map<int, int> m; // 分别代表爱好，和对应所在的cluster
    vector<set<int>> clusters;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int hobs;
        scanf("%d:", &hobs);
        vector<int> v(hobs);
        for (int j = 0; j < hobs; j++)
        {
            int hobby;
            cin >> hobby;
        }
        bool flag = false; // 标识是否已经找到团体
        int index;         // 已找到团体的下标
        for (int j = 0; j < hobs; j++)
        {
        }
    }
    system("pause");
    return 0;
}