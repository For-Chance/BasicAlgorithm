# 1092 To Buy or Not to Buy

> part 2, 2.2



## 自己解法


```c++
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
```



## 大神解法

- 柳神

```c++
#include <iostream>
using namespace std;
int book[256];
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        book[a[i]]++;
    int result = 0;
    for (int i = 0; i < b.length(); i++) {
        if (book[b[i]] > 0)
            book[b[i]]--;
        else
            result++;
    }
    if(result != 0)
        printf("No %d", result);
    else
        printf("Yes %d", a.length() - b.length());
    return 0;
}
```

