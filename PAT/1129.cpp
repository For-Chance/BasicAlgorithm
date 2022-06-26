#include <bits/stdc++.h>
using namespace std;

struct node
{
    int tag, fre;
    node(int tag, int fre) : tag(tag), fre(fre) {}
    bool operator<(const node &a) const
    {
        return (this->fre == a.fre) ? this->tag < a.tag : this->fre > a.fre;
    }
};

int main()
{
    int N, K;
    cin >> N >> K;
    set<node> nums;
    vector<int> book(50003, 0);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (i != 0)
        {
            cout << x << ": ";
            int cnt = 0;
            for (auto it = nums.begin(); it != nums.end() && cnt < K; it++)
            {
                if (it != nums.begin())
                    cout << ' ' << (*it).tag;
                else
                    cout << (*it).tag;
                cnt++;
            }
            cout << endl;
        }
        auto pos = nums.find(node(x, book[x]));
        if (pos != nums.end())
            nums.erase(pos);
        book[x]++;
        nums.insert(node(x, book[x]));
    }
    system("pause");
    return 0;
}