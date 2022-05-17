# 1104 Sum of Number Segments

> part 3, 3.0



## 自己解法

- 以后WA如果没有明显的逻辑错误就很有可能是类型错了

- long %ld

  long long %lld

  float %f

  double %f 在C99及C++中，可以用%lf

  long double %Lf Linux可以直接用，Windows要加宏定义(详见下文)

  char %c

  char*(char[]) %s

  string(C++类型) %s printf("%s",string.c_str());

  long double: 大写L,加f输出long double。最后的f小写和大写没影响，但是第一个 l 必须大写成L。

```c++
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int lnum, rnum;
    long double sum = 0.0, a;
    for (int i = 1; i <= N; i++)
    {
        lnum = i;
        rnum = N - i + 1;
        cin >> a;
        sum += a * lnum * rnum;
    }
    printf("%.2Lf\n", sum);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    double temp;
    for (int i = 1; i <= n; i++) { 
        cin >> temp;
        sum += (long long)(temp * 1000) * i * (n - i + 1);
    }
    printf("%.2f", sum / 1000.0);
    return 0;
}
```

