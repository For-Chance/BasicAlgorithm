#include <iostream>
using namespace std;
#include <math.h>
#include <vector>
int N, K, P, n;
// 从 2 开始
int v[200];
vector<int> result;
int maxSum = -1;

bool dfs(int target, int rest, int sum)
{
    // target 是目前的目标
    // rest 是目前剩下可以的算数
    if (target == 0 && rest == 0)
    {
        if (sum > maxSum)
        {
            result.clear();
            return true;
        }
    }
    if (target < 4)
        return false;
    int n = sqrt(target);
    int index = n - 2;
    if (v[index] * rest < target)
        return false;
    int min = sqrt((double)target / (double)rest) - 2;
    if (min < 0)
        min = 0;
    for (int i = index; i >= min; i--)
    {
        if (dfs(target - v[i], rest - 1, sum + i + 2) == true)
        {
            result.push_back(i + 2);
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> K >> P;
    n = sqrt(N);
    for (int i = 0; i <= n - 2; i++)
    {
        v[i] = pow(i + 2, P);
    }
    // 从大数开始dfs
    bool flag = dfs(N, K, 0);
    if (result.size() == K)
    {
        cout << N << " =";
        for (int i = 0; i < K; i++)
            if (i == 0)
                printf(" %d^%d", result[i], P);
            else
                printf(" + %d^%d", result[i], P);
    }
    else
    {
        cout << "Impossible";
    }
    cout << endl;
    system("pause");
    return 0;
}