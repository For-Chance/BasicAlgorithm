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

    for (map<int, float>::iterator it = p2.begin(); it != p2.end(); it++)
    {
        map<int, float>::iterator pos = p1.find(it->first);
        if (pos != p1.end())
        {
            pos->second += it->second;
            if (pos->second == 0.0)
                p1.erase(pos->first);
        }
        else
            p1.insert(make_pair(it->first, it->second));
    }

    cout << p1.size();
    for (map<int, float>::iterator it = p1.begin(); it != p1.end(); it++)
        cout << " " << it->first << " " << fixed << setprecision(1) << it->second;
    cout << endl;

    system("pause");
    return 0;
}