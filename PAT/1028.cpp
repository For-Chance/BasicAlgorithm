#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int C;

struct student
{
    int ID;
    string name;
    int grades;
};

bool cmpC1(student a, student b)
{
    return a.ID < b.ID;
}
bool cmpC2(student a, student b)
{
    return a.name == b.name ? a.ID < b.ID : a.name < b.name;
}
bool cmpC3(student a, student b)
{
    return a.grades == b.grades ? a.ID < b.ID : a.grades < b.grades;
}

int main()
{
    int N;
    cin >> N >> C;
    vector<student> stu(N);
    for (int i = 0; i < N; i++)
        cin >> stu[i].ID >> stu[i].name >> stu[i].grades;
    if (C == 1)
        sort(stu.begin(), stu.end(), cmpC1);
    else if (C == 2)
        sort(stu.begin(), stu.end(), cmpC2);
    else
        sort(stu.begin(), stu.end(), cmpC3);
    for (int i = 0; i < N; i++)
    {
        printf("%06d", stu[i].ID);
        cout << " " << stu[i].name << " " << stu[i].grades << endl;
    }
    system("pause");
    return 0;
}