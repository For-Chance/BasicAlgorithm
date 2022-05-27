#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 返回缺页次数
    double LRU(vector<int> &files, int M)
    {
        int N = files.size();
        // 文件id，最近输入的位置
        unordered_map<int, int> m;
        // 最近输入的位置,文件id
        map<int, int> m2;
        int maxid = 0;
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            // i 表示目前输入的位置
            auto pos = m.find(files[i]);
            if (pos == m.end())
            {
                // 缺页
                count++;
                if (m.size() == M)
                {
                    // 置换
                    // 将m2第一删去就行
                    // 先删再加
                    int deleteid = m2.begin()->second;
                    m.erase(deleteid);
                    m2.erase(m2.begin());
                }
                m[files[i]] = i;
                m2[i] = files[i];
            }
            else
            {
                // m2 先删掉再增加
                m2.erase(pos->second);
                pos->second = i;
                m2[i] = pos->second;
            }
        }
        return (double)count / (double)N;
    }
};

int main()
{
    int M;
    vector<int> files;
    ifstream infile;
    infile.open("input2.txt");
    infile >> M;
    int a;
    while (infile >> a)
    {
        files.push_back(a);
    }
    infile.close();
    Solution solution;
    double res = solution.LRU(files, M);
    printf("file hit ratio: %.2f.\n", res);
    system("pause");
    return 0;
}