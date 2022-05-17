#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

void getDaynHour(string s1, string s2)
{
    string repDay[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string repHour = "0123456789ABCDEFGHIJKLMN";
    string Day;
    int Hour;
    int flag = 0; // flag = 0 表示 Day 还没找到，不能找 Hour
    for (int i = 0; i < s1.length(); i++)
        for (int j = 0; j < s2.length(); j++)
        {
            if (flag == 1 && s1[i] == s2[j] && i == j && repHour.find(s1[i]) != string::npos)
            {
                Hour = repHour.find(s1[i]);
                break;
            }
            if (s1[i] == s2[j] && i == j && s1[i] - 'A' < 7 && s1[i] - 'A' >= 0 && flag == 0)
            {
                Day = repDay[s1[i] - 'A'];
                flag = 1;
            }
        }
    cout << Day << " ";
    printf("%02d:", Hour);
}

void getMinute(string s3, string s4)
{
    string repMinute = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int Minute;
    for (int i = 0; i < s3.length(); i++)
        for (int j = 0; j < s4.length(); j++)
        {
            if (s3[i] == s4[j] && i == j && repMinute.find(s3[i]) != string::npos)
            {
                Minute = i;
                break;
            }
        }
    printf("%02d", Minute);
}

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    getDaynHour(s1, s2);
    getMinute(s3, s4);
    cout << endl;
    system("pause");
    return 0;
}
