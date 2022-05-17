#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n1;
    cin >> n1;
    int s1[200000];
    for (int i = 0; i < n1; i++)
        cin >> s1[i];
    int n2;
    cin >> n2;
    int s2[200000];
    for (int i = 0; i < n2; i++)
        cin >> s2[i];
    int mid = (n1 + n2 + 1) / 2;
    int l1 = 0, l2 = 0;
    for (int i = 0;; i++)
        if (l2 == n2 || l1 < n1 && s1[l1] < s2[l2])
        {
            if (i + 1 == mid)
            {
                cout << s1[l1] << endl;
                break;
            }
            l1++;
        }
        else
        {
            if (i + 1 == mid)
            {
                cout << s2[l2] << endl;
                break;
            }
            l2++;
        }
    system("pause");
    return 0;
}