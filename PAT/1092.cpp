#include <iostream>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int a_size = a.size();
    int b_size = b.size();
    int h = 0, j = 0;
    for (int i = 0; i < b_size; i++)
    {
        int pos = a.find(b[i]);
        if (pos == string::npos)
            j++;
        else
            a[pos] = '_';
    }

    if (j == 0)
        cout << "Yes " << a_size - b_size << endl;
    else
        cout << "No " << j << endl;
    system("pause");
    return 0;
}