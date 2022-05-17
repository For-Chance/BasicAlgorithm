#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class person
{
public:
    person(int ID, int V, int T, int H)
    {
        this->ID = ID;
        this->V = V;
        this->T = T;
        this->sum = V + T;
        if (V >= H && T >= H)
            this->flag = 1;
        else if (V >= H && T < H)
            this->flag = 2;
        else if (V < H && V >= T)
            this->flag = 3;
        else
            this->flag = 4;
    }

    int ID;
    int V, T;
    int sum, flag; // flag = 1 是 sages(V>=H,T>=H)，flag = 2 是 nobleman(V>=H,T<H), flag = 3 是 foolman(T=<V<H)
};

bool cmp(person a, person b)
{
    return a.flag != b.flag ? a.flag < b.flag : (a.sum != b.sum ? a.sum > b.sum : (a.V != b.V ? a.V > b.V : a.ID < b.ID));
}

int main()
{
    int N, L, H;
    cin >> N >> L >> H;
    vector<person> v;
    for (int i = 0; i < N; i++)
    {
        int ID, V, T;
        cin >> ID >> V >> T;
        if (V >= L && T >= L)
        {
            person p(ID, V, T, H);
            v.push_back(p);
        }
    }
    sort(v.begin(), v.end(), cmp);
    int v_size = v.size();
    cout << v_size << endl;
    for (int i = 0; i < v_size; i++)
        cout << v[i].ID << " " << v[i].V << " " << v[i].T << endl;

    system("pause");
    return 0;
}