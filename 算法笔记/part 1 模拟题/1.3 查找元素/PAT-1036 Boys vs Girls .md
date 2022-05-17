# 1036 Boys vs Girls

> part 1, 1.3



## 自己解法

```c++
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
```



## 大神解法

- 柳神
- 和自己的差不多

```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string female, male;
    int femalescore = -1, malescore = 101;
    for(int i = 0; i < n; i++) {
        string name, sex, num;
        int score;
        cin >> name >> sex >> num;
        scanf("%d", &score);
        if(sex == "F") {
            if(femalescore < score) {
                femalescore = score;
                female = name + " " + num;
            }
        } else if(malescore > score) {
                malescore = score;
                male = name + " " + num;
            }
    }
    if(femalescore != -1)
        cout << female << endl;
    else
        printf("Absent\n");
    if(malescore != 101)
        cout << male << endl;
    else
        printf("Absent\n");
    if(femalescore != -1 && malescore != 101)
        printf("%d", femalescore - malescore);
    else
        printf("NA");
    return 0;
}
```

