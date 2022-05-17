# S2021D-路径

> part 5, 5.0 动态规划



## 题意理解

![在这里插入图片描述](https://img-blog.csdnimg.cn/946725cfd8e44bc3af948eeced34024e.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)



## 自己解法

- 

```c++

```



## 大神解法

![image-20220406114713451](C:/Users/mechrevo/AppData/Roaming/Typora/typora-user-images/image-20220406114713451.png)

```c++

#include <bits/stdc++.h>
using namespace std;

const int maxn = 21;
long long int dp[1 << maxn][maxn];

bool IsPosVis(int state, int pos) {
  if ((state & (1 << pos)) != 0) {
    return true;
  } else {
    return false;
  }
}

bool IsConnect(int x, int y) {
  if (x == 0 || y == 0) {
    return true;
  }
  if (__gcd(x + 1, y + 1) == 1) {
    return true;
  } else {
    return false;
  }
}

long long int f(int state, int finalPos) {
  if (dp[state][finalPos] != -1) {
    return dp[state][finalPos];
  }
  if (!IsPosVis(state, finalPos)) {
    return dp[state][finalPos] = 0;
  }

  long long int ret = 0;

  for (int net = 0; net < maxn; net++) {
    if (!IsPosVis(state, net)) {
      continue;
    }
    if (!IsConnect(net, finalPos)) {
      continue;
    }
    ret += f(state - (1 << finalPos), net);
  }

  return dp[state][finalPos] = ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  long long int ans = 0;
  int finalState = (1 << (maxn)) - 1;
  dp[1][0] = 1;

  for (int i = 0; i < maxn; i++) {
    long long int temp = f(finalState, i);
    printf("%d %d %d %lld\n", IsConnect(i, 0), finalState, i, temp);
    ans += temp;
  }
  printf("ans = %lld\n", ans);
  return 0;
}

```
