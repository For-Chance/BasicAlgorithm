#include <iostream>
using namespace std;

int main()
{
    int lowM = 10000, hignW = -10000;
    int ilowM = -1, ihignW = -1, i = 0;
    string name[1000], ID[1000];
    int N;
    cin >> N;
    while (N--)
    {
        char gender;
        int grade;
        cin >> name[i] >> gender >> ID[i] >> grade;
        if (gender == 'M' && grade <= lowM)
        {
            lowM = grade;
            ilowM = i;
        }
        if (gender == 'F' && grade >= hignW)
        {
            hignW = grade;
            ihignW = i;
        }
        i++;
    }

    if (ihignW == -1)
        cout << "Absent" << endl;
    else
        cout << name[ihignW] << " " << ID[ihignW] << endl;
    if (ilowM == -1)
        cout << "Absent" << endl;
    else
        cout << name[ilowM] << " " << ID[ilowM] << endl;
    if (ihignW == -1 || ilowM == -1)
        cout << "NA" << endl;
    else
        cout << hignW - lowM << endl;
    system("pause");
    return 0;
}