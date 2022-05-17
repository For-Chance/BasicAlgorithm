#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    cin >> N >> M;
    int V1, V2;
    vector<int> d;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        d.push_back(n);
    }
    int flag = 0;
    sort(d.begin(), d.end());
    for (vector<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        int target = M - *it;
        vector<int>::iterator pos = find(d.begin(), d.end(), target);
        if (pos == d.end() || *pos == *it)
            continue;
        cout << *it << " " << *pos << endl;
        flag = 1;
        break;
    }
    if (flag == 0)
        cout << "No Solution" << endl;

    system("pause");
    return 0;
}