#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// K <= 5
int partial_score[5];

struct person
{
    int uid = -1;
    int rank = 0, total_score = 0;
    int s[5] = {-1, -1, -1, -1, -1};
    bool isshow = false;
};

int countP(person p)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
        if (partial_score[i] == p.s[i])
            count++;
    return count;
}

bool cmp(person a, person b)
{
    if (a.isshow == true && b.isshow == false)
        return true;
    else if (a.isshow == false && b.isshow == true)
        return false;
    else
        return a.total_score != b.total_score ? a.total_score > b.total_score : (countP(a) != countP(b) ? countP(a) > countP(b) : a.uid < b.uid);
}

int main()
{
    int N, K, M;
    cin >> N >> K >> M;
    for (int i = 0; i < K; i++)
        cin >> partial_score[i];
    vector<person> v(N + 1);
    for (int i = 0; i < M; i++)
    {
        int uid, nid, pso;
        cin >> uid >> nid >> pso;
        if (pso == -1)
        {
            if (v[uid].isshow == false)
                continue;
            else
                pso = 0;
        }
        v[uid].uid = uid; // pso == -1和0都为0
        nid--;
        if (v[uid].s[nid] < pso)
        {
            v[uid].isshow = true;
            if (v[uid].s[nid] == -1)
                v[uid].total_score += pso;
            else
                v[uid].total_score += pso - v[uid].s[nid]; // 因为有if条件在，所以 total_score 是不会加上 -1 的
            v[uid].s[nid] = pso;
        }
    }
    sort(v.begin(), v.end(), cmp); // 注意这里sort后从0开始

    for (int i = 0; v[i].isshow != false; i++)
    {
        if (i == 0 || v[i].total_score != v[i - 1].total_score) // 注意 i = 0 放前面
            v[i].rank = i + 1;
        else
            v[i].rank = v[i - 1].rank;
        printf("%d %05d %d", v[i].rank, v[i].uid, v[i].total_score);
        for (int j = 0; j < K; j++)
            if (v[i].s[j] == -1)
                cout << " -";
            else
                cout << " " << v[i].s[j];
        cout << endl;
    }
    system("pause");
    return 0;
}