#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <math.h>

struct person
{
    string name;
    int age;
    int worth;
};

bool cmp(person a, person b)
{
    return a.age < b.age;
}

bool cmp2(person a, person b)
{
    return a.worth != b.worth ? a.worth > b.worth : (a.age != b.age ? a.age < b.age : a.name < b.name);
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<person> ps(N);
    for (int i = 0; i < N; i++)
        cin >> ps[i].name >> ps[i].age >> ps[i].worth;
    sort(ps.begin(), ps.end(), cmp);
    // for (int i = 0; i < N; i++)
    //     cout << ps[i].name << " " << ps[i].age << " " << ps[i].worth << endl;
    vector<person> temp;
    for (int i = 0; i < K; i++)
    {
        temp.clear(); //这种方法不回收空间
        int M, Amin, Amax;
        cin >> M >> Amin >> Amax;
        // 下面这个循环可以用二分替代
        int count = 0;
        int j = 0;
        // if (ps[(j + N) / 2].age < Amin)
        //     j = (j + N) / 2;
        int low = 0, high = N - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (ps[mid].age < Amin)
                if (ps[mid + 1].age >= Amin)
                {
                    j = mid + 1;
                    break;
                }
                else
                    low = mid + 1;
            else if (ps[mid].age >= Amin)
                if (ps[mid - 1].age < Amin)
                {
                    j = mid;
                    break;
                }
                else
                    high = mid - 1;
        }
        for (; j < N; j++)
        {
            if (ps[j].age < Amin)
                continue;
            if (ps[j].age > Amax)
                break;
            temp.push_back(ps[j]);
            count++;
        }
        sort(temp.begin(), temp.end(), cmp2);
        cout << "Case #" << i + 1 << ":" << endl;
        if (temp.size() == 0)
        {
            cout << "None" << endl;
            continue;
        }
        int x = min(M, count);
        for (int j = 0; j < x; j++)
        {
            cout << temp[j].name << " " << temp[j].age << " " << temp[j].worth << endl;
        }
    }
    system("pause");
    return 0;
}