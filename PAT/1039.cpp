#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    int N, K;
    cin >> N >> K;
    map<string, vector<int>> m;
    for (int i = 0; i < K; i++)
    {
        int index, n;
        cin >> index >> n;
        for (int j = 0; j < n; j++)
        {
            string name;
            cin >> name;
            auto pos = m.find(name);
            if (pos == m.end())
            {
                vector<int> n;
                n.push_back(index);
                m.insert(make_pair(name, n));
            }
            else
                pos->second.push_back(index);
        }
    }
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        auto pos = m.find(name);
        if (pos == m.end())
            cout << name << " " << 0 << endl;
        else
        {
            sort(pos->second.begin(), pos->second.end());
            cout << pos->first << " " << pos->second.size();
            for (int j = 0; j < pos->second.size(); j++)
                cout << " " << pos->second[j];
            cout << endl;
        }
    }
    system("pause");
    return 0;
}