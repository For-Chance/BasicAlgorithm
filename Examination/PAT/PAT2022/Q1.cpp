#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, string> map;
    map[0] = "Sunday";
    map[1] = "Monday";
    map[2] = "Tuesday";
    map[3] = "Wednesday";
    map[4] = "Thursday";
    map[5] = "Friday";
    map[6] = "Saturday";
    unordered_map<int, string> map2;
    map2[0] = "yesterday";
    map2[1] = "today";
    map2[2] = "tomorrow";
    vector<int> k1(3);
    vector<int> k2(3);
    for (int i = 0; i < 3; i++)
        cin >> k1[i];
    for (int i = 0; i < 3; i++)
        cin >> k2[i];
    bool flag = false;
    for (int i = 0; i < 3; i++)
        if (k1[i] == k2[i])
        {
            int x;
            if (i == 0)
                x = 1;
            else if (i == 1)
                x = 0;
            else
                x = -1;
            cout << map[(k1[i] + x) % 7] << endl
                 << map2[i] << endl
                 << map2[i];
            flag = true;
            break;
        }
    if (!flag)
    {
        for (int i = 0; i < 3; i++)
        {
            int x;
            if (i == 0)
                x = 1;
            else if (i == 1)
                x = 0;
            else
                x = -1;
            int j = (i + 1) % 3;
            if ((k1[i] + 1) % 7 == k2[j])
            {
                flag = true;
                cout << map[(k1[i] + x) % 7] << endl
                     << map2[i] << endl
                     << map2[j];
                break;
            }
        }
        if (!flag)
        {
            for (int i = 0; i < 3; i++)
            {
                int x;
                if (i == 0)
                    x = 1;
                else if (i == 1)
                    x = 0;
                else
                    x = -1;
                int j = (i - 1) % 3;
                if ((k1[i] - 1) % 7 == k2[j])
                {
                    flag = true;
                    cout << map[(k1[i] + x) % 7] << endl
                         << map2[i] << endl
                         << map2[j];
                    break;
                }
            }
        }
    }

    system("pause");
    return 0;
}