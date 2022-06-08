#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_set<int> count;
    int find_index(vector<vector<int>> &arr, int &q)
    {
        int n = arr.size();
        if (n == 0)
            return -1;
        int s = 0;
        int next = arr[0][1];
        int i = 0;
        while (s + next <= q)
        {
            s = s + next;
            i++;
            if (i >= n)
                return -1;
            next = arr[i][1];
        }
        count.insert(i);
        return arr[i][0] + 4 * (q - s);
    }
};

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> arr(N, vector<int>(2));
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    Solution solution;
    for (int i = 0; i < K; i++)
    {
        int q;
        cin >> q;
        int index = solution.find_index(arr, q);
        if (index == -1)
            cout << "Illegal Access" << endl;
        else
            cout << index << endl;
    }
    cout << solution.count.size() << endl;
    system("pause");
    return 0;
}

// 用时25m