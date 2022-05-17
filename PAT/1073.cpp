#include <iostream>
using namespace std;
#include <string>

int main()
{
    string s;
    cin >> s;
    string snum1 = "", snum2 = ""; // 表示前后两个数字
    int pos_split = s.find("E");
    int s_len = s.length();
    snum1 = s.substr(0, pos_split);
    snum2 = s.substr(pos_split + 1);
    int num2 = stoi(snum2);
    // 把sum1 继续拆分
    string sign = snum1.substr(0, 1);
    sign = (sign == "+") ? "" : "-";
    string b_dim = snum1.substr(1, 1);
    string a_dim = snum1.substr(3);
    string result = "";
    int shift_pos = 0; // 移动的位数
    if (num2 >= 0)
    {
        int a_dim_len = a_dim.length();
        if (num2 >= a_dim_len)
        {
            string s_zero;
            s_zero.assign(num2 - a_dim_len, '0');
            result += sign + b_dim + a_dim + s_zero;
        }
        else
            result += sign + b_dim + a_dim.substr(0, num2) + "." + a_dim.substr(num2);
    }
    else
    {
        string s_zero;
        s_zero.assign((-num2) - 1, '0');
        result += sign + "0." + s_zero + b_dim + a_dim;
    }
    cout << result << endl;
    system("pause");
    return 0;
}