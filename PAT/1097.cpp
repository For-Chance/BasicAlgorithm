#include <iostream>
using namespace std;
#include <vector>
#include <map>

struct node
{
    int address;
    int key;
    int next;
    bool flag;
};
vector<node> v(100000);
map<int, int> m;
vector<node> list;
vector<node> rest;

int main()
{
    int begin, N;
    cin >> begin >> N;
    int addr;
    for (int i = 0; i < N; i++)
    {
        cin >> addr;
        cin >> v[addr].key >> v[addr].next;
        v[addr].address = addr;
        v[i].flag = false;
    }
    for (int i = begin; i != -1; i = v[i].next)
        v[i].flag = true;
    for (int i = begin; i != -1; i = v[i].next)
    {
        m[abs(v[i].key)]++;
        if (m[abs(v[i].key)] == 1)
            list.push_back(v[i]);
        else
            rest.push_back(v[i]);
    }
    for (int i = 0; i < list.size(); i++)
        if (i != list.size())
            cout << v[i].address << v[i].key << v[i + 1].address << endl;
        else
            cout << v[i].address << v[i].key << -1 << endl;
    for (int i = 0; i < rest.size(); i++)
        if (i != list.size())
            cout << v[i].address << v[i].key << v[i + 1].address << endl;
        else
            cout << v[i].address << v[i].key << -1 << endl;
    system("pause");
    return 0;
}