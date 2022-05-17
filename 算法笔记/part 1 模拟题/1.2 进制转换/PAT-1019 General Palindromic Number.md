# 1019 General Palindromic Number

> part 1, 1.2



## 自己解法(未全对)

- 有一个WA
- 可惜题目并没有限制base为10进制以内，不然如下用string做巨快

```c++
#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    int N, base;
    cin >> N >> base;
    string res = "";
    do
    {
        res += to_string(N % base);
        N = N / base;
        if (N)
            res += " ";
    } while (N);
    string res_r = res;
    reverse(res_r.begin(), res_r.end());
    if (res_r.compare(res) == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << res_r << endl;

    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 中规中矩的做法，比较稳妥，也不难实现

```c++
#include <cstdio>
using namespace std;
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int arr[40], index = 0;
	while(a != 0) {
		arr[index++] = a % b;
		a = a / b;
	}
	int flag = 0;
	for(int i = 0; i < index / 2; i++) {
		if(arr[i] != arr[index-i-1]) {
			printf("No\n");
			flag = 1;
			break;
		}
	}
	if(!flag) printf("Yes\n");
	for(int i = index - 1; i >= 0; i--) {
		printf("%d", arr[i]);
		if(i != 0) printf(" ");
	}
	if(index == 0)
		printf("0");
	return 0;
}
```



