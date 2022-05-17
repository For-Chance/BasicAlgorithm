#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct stu
{
    string name, ID;
    int grade;
};

bool cmp(stu a, stu b)
{
    return a.grade > b.grade;
}

int main()
{
    int N;
    cin >> N;
    vector<stu> s(N);
    for (int i = 0; i < N; i++)
        cin >> s[i].name >> s[i].ID >> s[i].grade;
    int g1, g2;
    cin >> g1 >> g2;
    sort(s.begin(), s.end(), cmp);
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i].grade > g2)
            continue;
        if (s[i].grade < g1)
            break;
        flag = 1;
        cout << s[i].name << " " << s[i].ID << endl;
    }
    if (!flag)
        cout << "NONE" << endl;
    system("pause");
    return 0;
}