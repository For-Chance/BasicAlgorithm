#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <math.h>

int getnum(char c)
{
    // 0-9 a-z 获得数字
    if (int(c) >= '0' && int(c) <= '9')
        return int(c) - '0';
    else
        return int(c) - 'a' + 10;
}

long long getdec(string N, int r)
{
    // 将 N 字符串转换为 r 进制输出匹配的10进制数
    long long dec = 0;
    int len_n = N.length();
    // 对 N 进行翻转，更方便一些
    reverse(N.begin(), N.end());
    for (int i = 0; i < len_n; i++)
    {
        int num = getnum(N[i]);
        dec += num * pow(r, i);
        if (num >= r)
            return -1;
    }
    return dec;
}

long long guessRadix(long long dec, string N)
{
    string N_copy = N;
    sort(N_copy.begin(), N_copy.end(), greater<char>());
    long long low = getnum(N_copy[0]) + 1;
    long long high = max(dec, low);
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long dec2 = getdec(N, mid);
        if (dec == dec2)
        {
            return mid;
        }
        else if (dec2 > dec || dec2 < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    long long dec_N1, dec_N2, res;
    if (tag == 1)
    {
        dec_N1 = getdec(N1, radix);
        res = guessRadix(dec_N1, N2);
    }
    else
    {
        dec_N2 = getdec(N2, radix);
        res = guessRadix(dec_N2, N1);
    }
    if (res == -1)
        cout << "Impossible" << endl;
    else
        cout << res << endl;
    system("pause");
    return 0;
}