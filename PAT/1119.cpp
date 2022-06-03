#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getInorder(vector<int> &pre, vector<int> &post)
    {
        int n = pre.size();
        vector<int> in;
        getin(pre, post, in, 0, n - 1, 0, n - 1);
        return in;
    }

    bool unique = true;
    void getin(vector<int> &pre, vector<int> &post, vector<int> &in, int preLeft, int preRight, int postLeft, int postRight)
    {
        if (preLeft == preRight)
        {
            in.push_back(pre[preLeft]);
            return;
        }
        if (pre[preLeft] == post[postRight])
        {
            int i = preLeft + 1;
            while (i <= preRight && pre[i] != post[postRight - 1])
                i++;
            // i 为分隔左右子树的位置
            if (i - preLeft > 1)
                getin(pre, post, in, preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
            else
                unique = false;
            in.push_back(post[postRight]);
            getin(pre, post, in, i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
        }
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> preorder(N);
    for (int i = 0; i < N; i++)
        cin >> preorder[i];
    vector<int> postorder(N);
    for (int i = 0; i < N; i++)
        cin >> postorder[i];
    Solution solution;
    vector<int> result = solution.getInorder(preorder, postorder);
    cout << ((solution.unique) ? "Yes\n" : "No\n");
    cout << result[0];
    for (int i = 1; i < N; i++)
        cout << " " << result[i];
    cout << endl;
    system("pause");
    return 0;
}