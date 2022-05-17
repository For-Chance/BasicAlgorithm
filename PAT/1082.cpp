#include <iostream>
using namespace std;

string getDigit(char c)
{
    string s;
    switch (c)
    {
    case '0':
        s = "ling";
        break;
    case '1':
        s = "yi";
        break;
    case '2':
        s = "er";
        break;
    case '3':
        s = "san";
        break;
    case '4':
        s = "si";
        break;
    case '5':
        s = "wu";
        break;
    case '6':
        s = "liu";
        break;
    case '7':
        s = "qi";
        break;
    case '8':
        s = "ba";
        break;
    case '9':
        s = "jiu";
        break;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    string sn = to_string(n);
    int len_sn = sn.length();
    string repUnit[8] = {"Yi", "Qian", "Bai", "Shi", "Wan", "Qian", "Bai", "Shi"};
    int i = 0;
    if (n < 0)
    {
        i++;
        cout << "Fu ";
    }
    for (; i < len_sn - 1; i++)
    {
        if (sn[i] != '0')
        {
            cout << getDigit(sn[i]) << " ";
            cout << repUnit[9 - len_sn + i] << " ";
        }else{
            
        }
    }
    cout << getDigit(sn[i]) << endl;
    system("pause");
    return 0;
}