#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int N, min = 2000000000, max = -1;
    cin >> N;
    vector<int> d(N);
    vector<int> rightMin(N);
    vector<int> leftMax(N);
    leftMax[0] = -1;
    rightMin[N - 1] = 2000000000;
    cin >> d[0];
    for (int i = 1; i < N; i++)
    {
        cin >> d[i];
        if (d[i - 1] > max)
            max = d[i - 1];
        leftMax[i] = max;
    }
    for (int i = N - 2; i >= 0; i--)
    {
        if (d[i + 1] < min)
            min = d[i + 1];
        rightMin[i] = min;
    }
    int count = 0;
    vector<int> res;
    for (int i = 0; i < N; i++)
        if (d[i] > leftMax[i] && d[i] < rightMin[i])
            res.push_back(d[i]);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        if (i == 0)
            cout << res[i];
        else
            cout << ' ' << res[i];
    cout << endl;
    system("pause");
    return 0;
}