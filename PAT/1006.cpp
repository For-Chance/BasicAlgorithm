#include <iostream>
using namespace std;
#include <string>

int main()
{
    int M;
    cin >> M;
    string earliest, latest;
    int e[3] = {24}, l[3] = {0};
    while (M--)
    {
        string name;
        int sh, sm, ss, eh, em, es;
        cin >> name;
        scanf("%d:%d:%d %d:%d:%d", &sh, &sm, &ss, &eh, &em, &es);

        if (sh < e[0] || (sh == e[0] && sm < e[1]) || (sh == e[0] && sm == e[1] && ss < e[2]))
        {
            earliest = name;
            e[0] = sh;
            e[1] = sm;
            e[2] = ss;
        }
        if (eh > l[0] || (eh == l[0] && em > l[1]) || (eh == l[0] && em == l[1] && es > l[2]))
        {
            latest = name;
            l[0] = eh;
            l[1] = em;
            l[2] = es;
        }
    }
    cout << earliest << " " << latest << endl;
    system("pause");
    return 0;
}