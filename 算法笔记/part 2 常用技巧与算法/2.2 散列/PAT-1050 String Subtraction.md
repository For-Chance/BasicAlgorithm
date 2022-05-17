# 1050 String Subtraction

> part 2, 2.2



## 自己解法

- 很多时候，STL的算法已经足够快了


```c++
#include <iostream>
using namespace std;
#include <string>

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int s1_size = s1.size();
    int s2_size = s2.size();
    for (int i = 0; i < s1_size; i++)
        if (s2.find(s1[i]) == string::npos)
            cout << s1[i];
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char s1[100000], s2[100000];
int main() {
    cin.getline(s1, 100000);
    cin.getline(s2, 100000);
    int lens1 = strlen(s1), lens2 = strlen(s2);
    bool flag[256] = {false};
    for(int i = 0; i < lens2; i++)
        flag[s2[i]] = true;
    for(int i = 0; i < lens1; i++) {
        if(!flag[s1[i]])
            printf("%c", s1[i]);
    }
    return 0;
}
```

