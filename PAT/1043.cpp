#include <iostream>
using namespace std;
#include <vector>

bool isM = false;
vector<int> pre, post;

void getpost(int root, int tail)
{
    int i = root + 1, j = tail;
    if (!isM)
    {
        while (i <= tail && pre[i] < pre[root])
            i++;
        while (j > root && pre[j] >= pre[root])
            j--;
    }
    else
    {
        while (i <= tail && pre[i] >= pre[root])
            i++;
        while (j > root && pre[j] < pre[root])
            j--;
    }
    if (i - j != 1)
        return;
    getpost(root + 1, i - 1);  // 先执行 left 部分，push_back 5 7 6, 然后 push_back 8 11 10
    getpost(j + 1, tail);      // 镜像的话, push_back 11 8 10, 然后 push_back 7 5 6
    post.push_back(pre[root]); // 最后 push_back 8
}

int main()
{
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        pre.push_back(k);
    }
    getpost(0, n - 1);
    if (post.size() != n)
    {
        isM = true;
        post.clear();
        getpost(0, n - 1);
    }
    if (post.size() == n)
    {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", post[i]);
    }
    else
    {
        printf("NO");
    }
    cout << endl;
    system("pause");
    return 0;
}