# 1011 World Cup Betting

> part 1, 1.3



## 自己解法

```c++
#include <iostream>
using namespace std;

float getGreat(float a[3])
{
    char rep[3] = {'W', 'T', 'L'};
    float max = 0;
    int index;
    for (int i = 0; i < 3; i++)
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    cout << rep[index] << " ";
    return max;
}

int main()
{
    float a[3], b[3], c[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    cin >> c[0] >> c[1] >> c[2];
    float e, f, g;
    e = getGreat(a);
    f = getGreat(b);
    g = getGreat(c);
    printf("%.2f\n", (e * f * g * 0.65 - 1) * 2);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <cstdio>
using namespace std;
int main() {
    char c[4] = {"WTL"};
    double ans = 1.0;
    for(int i = 0; i < 3; i++) {
        double maxvalue = 0.0;
        int maxchar = 0;
        for(int j = 0; j < 3; j++) {
            double temp;
            scanf("%lf", &temp);
            if(maxvalue <= temp) {
                maxvalue = temp;
                maxchar = j;
            }
        }
        ans *= maxvalue;
        printf("%c ", c[maxchar]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}
```

