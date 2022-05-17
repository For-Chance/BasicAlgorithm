#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <vector>
#include <algorithm>

class findKu
{
public:
    bool operator()(const map<string, int>::value_type &pair)
    {
        return pair.second >= 2;
    }
};

int main()
{
    int n;
    cin >> n;
    map<string, int> KuMap;
    while (n--)
    {
        string s = " ";
        string s2 = "";
        while (cin >> s)
        {
            if (cin.get() == '\n')
                break;
            s2 = s;
        }
        map<string, int>::iterator pos = KuMap.find(s2);
        if (pos != KuMap.end())
            (*pos).second++;
        else
            KuMap.insert(make_pair(s2, 1));
    }
    map<string, int>::iterator pos = find_if(KuMap.begin(), KuMap.end(), findKu());
    if (pos == KuMap.end())
        cout << "nai" << endl;
    else
        cout << pos->first.c_str() << endl;
    system("pause");
    return 0;
}