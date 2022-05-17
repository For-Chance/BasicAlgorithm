#include <iostream>
using namespace std;
#include <map>

int postOrder[30], inOrder[30];
map<int, int> v; // 这里必须用map，不然的话不符合性质

void getv(int root, int begin, int end, int index)
{
    if (begin > end)
        return;
    int i = begin;
    for (; i <= end; i++)
        if (inOrder[i] == postOrder[root])
            break; // 所得 i 为在inOrder中的root，从而把postOrder和inOrder分成两半
    v[index] = postOrder[root];
    getv(root - 1 - (end - i), begin, i - 1, 2 * index + 1); // 注意第一个参数只跟postOrder有关，且只有这个参数与其有关，只能用这个参数与其他计算而来的数(right的大小)组合
    getv(root - 1, i + 1, end, 2 * index + 2);
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> postOrder[i];
    for (int i = 0; i < N; i++)
        cin >> inOrder[i];
    getv(N - 1, 0, N - 1, 0);
    for (auto it = v.begin(); it != v.end(); it++)
        if (it != v.begin())
            cout << " " << it->second;
        else
            cout << it->second;
    cout << endl;
    system("pause");
    return 0;
}