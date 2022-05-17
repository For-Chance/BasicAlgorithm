#include <iostream>
using namespace std;
#include <map>
#include <algorithm>
#include <iomanip>

int main()
{
    map<int, float, greater<int>> p1;
    int n1;
    cin >> n1;
    while (n1--)
    {
        int N;
        float aN;
        cin >> N;
        cin >> aN;
        p1.insert(make_pair(N, aN));
    }
    map<int, float, greater<int>> p2;
    int n2;
    cin >> n2;
    while (n2--)
    {
        int N;
        float aN;
        cin >> N;
        cin >> aN;
        p2.insert(make_pair(N, aN));
    }
    map<int, float, greater<int>> p;

    for (map<int, float>::iterator it = p1.begin(); it != p1.end(); it++)
    {
        for (map<int, float>::iterator ip = p2.begin(); ip != p2.end(); ip++)
        {

            int f = it->first + ip->first;
            float s = (it->second) * (ip->second);
            if (s == 0.0)
                continue;
            map<int, float>::iterator pos = p.find(f);
            if (pos != p.end())
            {
                pos->second += it->second;
                if (pos->second == 0.0)
                    p.erase(pos->first);
            }
            else
                p.insert(make_pair(f, s));
        }
    }

    cout << p.size();
    for (map<int, float>::iterator it = p.begin(); it != p.end(); it++)
        cout << " " << it->first << " " << fixed << setprecision(1) << it->second;
    cout << endl;

    system("pause");
    return 0;
}