#include <iostream>
using namespace std;

void printColor(int c)
{
    int qu, re;
    qu = c / 13;
    re = c % 13;
    char repColor[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    cout << repColor[qu] << repColor[re];
}

int main()
{
    int R, G, B;
    cin >> R >> G >> B;
    cout << "#";
    printColor(R);
    printColor(G);
    printColor(B);
    cout << endl;
    system("pause");
    return 0;
}