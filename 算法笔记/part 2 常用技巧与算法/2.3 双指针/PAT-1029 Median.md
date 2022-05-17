# 1029 Median

> part 2, 2.3

## 自己解法

- 第20行的判断条件搞清楚就行

```c++
#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n1;
    cin >> n1;
    int s1[200000];
    for (int i = 0; i < n1; i++)
        cin >> s1[i];
    int n2;
    cin >> n2;
    int s2[200000];
    for (int i = 0; i < n2; i++)
        cin >> s2[i];
    int mid = (n1 + n2 + 1) / 2;
    int l1 = 0, l2 = 0;
    for (int i = 0;; i++)
        if (l2 == n2 || l1 < n1 && s1[l1] < s2[l2])
        {
            if (i + 1 == mid)
            {
                cout << s1[l1] << endl;
                break;
            }
            l1++;
        }
        else
        {
            if (i + 1 == mid)
            {
                cout << s2[l2] << endl;
                break;
            }
            l2++;
        }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 逻辑是一样的，但是写得更加优雅

```c++
#include <iostream>
const int maxn = 200005;
int n, m, a1[maxn], a2[maxn], cnt = 0, i, j, ans;
int main() {
	scanf("%d", &n);
	for(i = 1; i <= n; i++)	scanf("%d", &a1[i]);
	scanf("%d", &m);
	for(i = 1; i <= m; i++)	scanf("%d", &a2[i]);
	int target = (n + m + 1) / 2;
	i = 1, j = 1;
	while(i <= n && j <= m) {
		ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];
		if(++cnt == target)	break;
	}
	if(i <= n && cnt < target)	
		ans = a1[i + target - cnt - 1];
	else if(j <= m && cnt < target)	
		ans = a2[j + target - cnt - 1];
	printf("%d", ans);
	return 0;
}
```
