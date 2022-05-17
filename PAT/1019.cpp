#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    int N, base;
    cin >> N >> base;
    string res = "";
    do
    {
        res += to_string(N % base);
        N = N / base;
        if (N)
            res += " ";
    } while (N);
    string res_r = res;
    reverse(res_r.begin(), res_r.end());
    if (res_r.compare(res) == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << res_r << endl;

    system("pause");
    return 0;
}