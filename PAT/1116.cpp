#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getResult(vector<int> &rankist, int id)
    {
        vector<bool> isPrime(10001, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= 100; i++)
            for (int j = 2; j <= 100; j++)
                isPrime[i * j] = false;
        for (int i = 0; i < rankist.size(); i++)
        {
            if (id != rankist[i])
                continue;
            if (i == 0)
                return 1;
            else if (isPrime[i + 1] == true)
                return 2;
            else
                return 3;
        }
        return 4;
    }
};

int main()
{
    Solution solution;
    int N;
    cin >> N;
    vector<int> rankist(N);
    for (int i = 0; i < N; i++)
        cin >> rankist[i];
    int K;
    cin >> K;
    int id;
    // 1 表示 MA，2 Minion，3 Cho，4 Are
    unordered_map<int, int> hashtable;
    for (int i = 0; i < K; i++)
    {
        cin >> id;
        auto pos = hashtable.find(id);
        if (pos != hashtable.end())
        {
            if (hashtable[id] != 4)
                printf("%04d: Checked\n", id);
            else if (hashtable[id] == 4)
                printf("%04d: Are you kidding?\n", id);
        }
        else
        {
            hashtable[id] = solution.getResult(rankist, id);
            if (hashtable[id] == 1)
                printf("%04d: Mystery Award\n", id);
            else if (hashtable[id] == 2)
                printf("%04d: Minion\n", id);
            else if (hashtable[id] == 3)
                printf("%04d: Chocolate\n", id);
            else if (hashtable[id] == 4)
                printf("%04d: Are you kidding?\n", id);
        }
    }

    system("pause");
    return 0;
}