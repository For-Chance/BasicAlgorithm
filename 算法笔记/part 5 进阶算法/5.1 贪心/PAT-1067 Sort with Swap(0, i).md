# 1067 Sort with Swap(0, i)

> part 5, 5.1



## 题意理解

- 输入N个数字，与0交换，最终所得数列最少的方法

$$
3 5 7 2 6 4 9 0 8 1 \\
0 1 2 3 4 5 6 7 8 9
$$

- 注意0有可能多次出现在自己的位置上
  - 当0不在0的位置上时，每次与0交换当前位置正确的数，比如上面这个公式，就是swap(0,7)->swap(0,2)->...
  - 当0在自己的位置上时，就找下一个与自己不等的数交换

### Sample Input:

```in
10
3 5 7 2 6 4 9 0 8 1
```

### Sample Output:

```out
9
```



## 自己解法

- 超时了
- 牛客网不超时

```c++
#include <iostream>
using namespace std;
#include <map>

int main()
{
    int N;
    cin >> N;
    map<int, int> d;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        d.insert(make_pair(a, i)); // 总是要找 0，把a放在前面
    }
    int count = 0;
    while (1)
    {
        auto pos = d.find(0);
        if (pos->second == pos->first)
        {
            auto it = d.begin();
            for (; it != d.end(); it++)
                if (it->second != it->first)
                    break;
            if (it == d.end())
                break;
            int temp = pos->second;
            pos->second = it->second;
            it->second = temp;
            count++;
        }
        else
        {
            auto posindex = d.find(pos->second);
            int temp = pos->second;
            pos->second = posindex->second;
            posindex->second = temp;
            count++;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}
```

- 过了

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int N;
    cin >> N;
    vector<int> d(N);
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        d[a] = i;
    }
    int count = 0;
    int i = 1;
    while (1)
        if (d[0] != 0)
        {
            int temp = d[0];
            d[0] = d[d[0]];
            d[temp] = temp;
            count++;
        }
        else
        {
            while (d[i] == i && i < N)
                i++;
            if (i == N)
                break;
            int temp = d[0];
            d[0] = d[i];
            d[i] = temp;
            count++;
        }
    cout << count << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

- 分析：

  1.0号为哨兵， 用哨兵与其他数字交换，使其他数字回到有序的位置（最后有序时所处的位置），则排序完成

  2.a[t] = i; 表示t数字当前正在占着哪一个位置。 （如果想实时监测每个数字的位置，可以用 b 数组{b[a[i]] = i } 缓存一下数据，输出查看的）

  3.依次遍历每个位置i，如果当前位置不是与之对应的数字，那么我们让这哨兵来去该数执行操作回到正确位置

  4.数字如何被哨兵执行操作回到序的位置：

  如果哨兵此时不在自己有序的位置上，那就，先让哨兵去让他占的那个位置上的真正应该放的数字回到此位置，即交换哨兵和此数字，我们swap(a[0],a[a0])，直到哨兵在交换的过程中回到了自己的有序位置。字词再次检查该位置是不是应该放的数字（别的数字回到有序位置的时候即哨兵执行操作的过程中，有可能让此位置该有的数字回到位置）。如果此位置不是当前数字，那哨兵和他交换swap(a[0],a[i])，就是让他先去哨兵的有序位置待一会，等下一轮操作，哨兵会把他交换回来的。如果此位置已经是该数字了，那就什么都不做。

  5.当到达最后一个位置时候，两种情况 1）。如果第一个数字和最后一个数字都在自己的有序位置 那ok~ 2）.哨兵和最后一个数字互相占着对方的位置，那最后一个数字就是哨兵，交换一次后，哨兵在交换后的位置等待，就是已经回到自己的有序位置，此时排序也是完成的。此过程包括在4里面了，怕你们不理解，单独说一下～


```c++
#include <iostream>
using namespace std;
int main() {
    int n, t, cnt = 0, a[100010];
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> t;
    	a[t] = i;
    }
    for(int i = 1; i < n; i++) {
        if(i != a[i]) {
            while(a[0] != 0) {
                swap(a[0],a[a[0]]);
                cnt++;
            }
            if(i != a[i]) {
                swap(a[0],a[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
```

