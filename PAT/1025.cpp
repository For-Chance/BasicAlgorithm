#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

struct test
{
    long long number;
    int grade;
    int loc;
    int rank[2] = {0};
};

bool allRank(test a, test b)
{
    return a.grade == b.grade ? a.number < b.number : a.grade > b.grade;
}

bool locRank(test a, test b)
{
    return a.loc != b.loc ? a.loc < b.loc : (a.grade == b.grade ? a.number < b.number : a.grade > b.grade);
}

int main()
{
    vector<test> allTests;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            long long number;
            int grade;
            scanf("%lld %d", &number, &grade);
            test d;
            d.number = number;
            d.grade = grade;
            d.loc = i + 1;
            allTests.push_back(d);
        }
    }
    vector<test>::iterator z = allTests.begin();
    sort(allTests.begin(), allTests.end(), locRank);
    for (vector<test>::iterator it = z; it != allTests.end(); it++)
    {
        if ((*it).loc != (*(it - 1)).loc)
            z = it;
        if ((*it).grade != (*(it - 1)).grade || it == z)
            (*it).rank[1] = it - z + 1;
        else
            (*it).rank[1] = (*(it - 1)).rank[1];
    }
    z = allTests.begin();
    sort(allTests.begin(), allTests.end(), allRank);
    for (vector<test>::iterator it = z; it != allTests.end(); it++)
        if ((*it).grade != (*(it - 1)).grade || it == z)
            (*it).rank[0] = it - z + 1;
        else
            (*it).rank[0] = (*(it - 1)).rank[0];
    cout << allTests.size() << endl;
    for (vector<test>::iterator it = allTests.begin(); it != allTests.end(); it++)
    {
        printf("%lld", it->number);
        cout << " " << it->rank[0] << " " << it->loc << " " << it->rank[1] << endl;
    }
    system("pause");
    return 0;
}