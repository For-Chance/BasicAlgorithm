#include <iostream>
using namespace std;
#include <stack>
#include <vector>

stack<int> d;
vector<int> postOrder, inOrder;

// 注意第一个root不是下标是1-N的实数
void getpost(int root, int begin, int end)
{
    if (begin > end)
        return;
    int i = begin;
    for (; i <= end; i++)
        if (inOrder[i] == root)
            break;
    getpost(root + 1, begin, i - 1);
    getpost(root + 1 + i - begin, i + 1, end);
    postOrder.push_back(root);
}

int main()
{
    int N;
    cin >> N;
    string s;
    int k;
    // 按顺序就是preOrder, 出栈是inOrder
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> k;
            d.push(k);
        }
        else
        {
            inOrder.push_back(d.top());
            d.pop();
        }
    }
    // 下面就是根据preOrder(1-N), inOrder 得到postOrder就行
    getpost(1, 0, N - 1);
    for (int i = 0; i < N; i++)
        if (i != 0)
            cout << " " << postOrder[i];
        else
            cout << postOrder[i];
    cout << endl;
    system("pause");
    return 0;
}