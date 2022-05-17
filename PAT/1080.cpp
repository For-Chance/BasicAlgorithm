#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct applicant
{
    int seq;
    int GE, GI;
    double final;
    int choices[5] = {-1, -1, -1, -1, -1};
    int final_school = -1;
};

bool cmp(applicant a, applicant b)
{
    if (a.final != b.final)
        return a.final > b.final;
    else
    {
        if (a.GE != b.GE)
            return a.GE > b.GE;
        else // 这个else的内容是为了相同分数，相同志愿的人能相邻
        {
            for (int i = 0; a.choices[i] != -1; i++)
                if (a.choices[i] != b.choices[i])
                    return a.choices[i] < b.choices[i];
            return false; // 如果是排好序的经过这个函数，相同分数，相同志愿的人作比较会返回false
        }
    }
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> ad(M); // 用于保存录取的人
    vector<int> quota(M);
    for (int i = 0; i < M; i++)
        cin >> quota[i];

    vector<applicant> s(N);
    for (int i = 0; i < N; i++)
    {
        applicant a;
        cin >> a.GE >> a.GI;
        a.final = (a.GE + a.GI) / 2.0;
        for (int j = 0; j < K; j++)
            cin >> a.choices[j];
        a.seq = i;
        s[i] = a;
    }
    sort(s.begin(), s.end(), cmp);

    ad[s[0].choices[0]].push_back(s[0].seq);
    s[0].final_school = s[0].choices[0];
    for (int i = 1; i < N; i++)
    {
        int flag = 0; // flag == 1表示被录上了
        for (int j = 0; j < K; j++)
        {
            // j 是choices的下标
            // j_choice 是选择的学校序号
            int j_choice = s[i].choices[j];
            int s_size = ad[j_choice].size();
            if (s_size < quota[j_choice])
            {
                ad[j_choice].push_back(s[i].seq);
                s[i].final_school = j;
                flag = 1;
                break;
            }
            int i_final = s[i - 1].final_school;
            if (!flag && s[i - 1].GE == s[i].GE && s[i - 1].GI == s[i].GI && i_final == j_choice)
            {
                s[i].final_school = i_final;
                if (i_final != -1)
                {
                    ad[i_final].push_back(s[i].seq);
                    break;
                }
            }
        }
    }

    // cout << "排序后：" << endl;
    // for (int i = 0; i < N; i++)
    // {
    //     cout << s[i].seq << " " << s[i].GE << " " << s[i].GI << " " << s[i].final << " ";
    //     for (int j = 0; j < K; j++)
    //         cout << s[i].choices[j] << " ";
    //     cout << endl;
    // }

    // cout << endl;
    // cout << "最终输出：" << endl;

    for (int i = 0; i < M; i++)
    {
        sort(ad[i].begin(), ad[i].end());
        int j_size = ad[i].size();
        for (int j = 0; j < j_size; j++)
            cout << (j != 0 ? " " : "") << ad[i][j];
        cout << endl;
    }

    system("pause");
    return 0;
}