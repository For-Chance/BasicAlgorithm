#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool cmp(string a, string b)
{
    int lena = a.size(), lenb = b.size();
    int i = 0;
    while (1)
    {
        lena--;
        lenb--;
        if (a[i] != b[i])
            return a[i] < b[i];
        // lena 先减完，讲a的第一个和b的第i个比较，小的在前面
        if (lena == 0)
            return a[0] < b[i + 1];
        if (lenb == 0)
            return a[i + 1] < b[0];
        i++;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<string> s;
    string x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (stoi(x) != 0)
            s.push_back(x);
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size(); i++)
        if (i == 0)
            cout << stoi(s[i]);
        else
            cout << s[i];
    cout << endl;
    system("pause");
    return 0;
}