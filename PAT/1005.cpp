#include <iostream>
using namespace std;
int main()
{
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string n;
    cin >> n;
    int len = n.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += n[i] - '0';
    }
    string s_sum = to_string(sum);
    int len_sum = s_sum.length();
    for (int j = 0; j < len_sum; j++)
    {
        cout << s[s_sum[j] - '0'];
        if (j != len_sum - 1)
            cout << " ";
    }
    cout << "\n";
    system("pause");
    return 0;
}