#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const double errorvalue = -10000.0;
    void findAverage(vector<string> &nums)
    {
        int n = nums.size();
        double sum = 0.0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            double value = getLegal(nums[i]);
            if (value == errorvalue)
                cout << "ERROR: " << nums[i] << " is not a legal number" << endl;
            else
            {
                cnt++;
                sum += value;
            }
        }
        if (cnt > 1)
            printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
        else if (cnt == 1)
            printf("The average of 1 number is %f\n", sum);
        else
            printf("The average of 0 numbers is Undefined\n");
    }

    double getLegal(string str)
    {
        // 不合法返回errorvalue
        int len = str.length();
        double value = 0;
        // 找到小数点
        int cnt_dot = 0, index_dot = len;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '.')
            {
                cnt_dot++;
                index_dot = i;
            }
        }
        if (cnt_dot > 1)
            return errorvalue;
        if (len - index_dot - cnt_dot > 2)
            return errorvalue;
        for (int i = 0; i < index_dot; i++)
        {
            if (str[i] == '-')
                continue;
            if (!isalnum(str[i]))
                return errorvalue;
            if (str[i] - '0' > 9)
                return errorvalue;
            value += (str[i] - '0') * pow(10, index_dot - i - 1);
        }
        for (int i = index_dot + 1; i < len; i++)
        {
            if (!isalnum(str[i]))
                return errorvalue;
            if (str[i] - '0' > 9)
                return errorvalue;
            value += (str[i] - '0') * pow(10, index_dot - i);
        }
        if (value > 1000)
            return errorvalue;
        if (str[0] == '-')
            value = -value;
        return value;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<string> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    Solution solution;
    solution.findAverage(nums);
    system("pause");
    return 0;
}