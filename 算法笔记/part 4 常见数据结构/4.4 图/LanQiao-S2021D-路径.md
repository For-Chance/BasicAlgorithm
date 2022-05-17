# S2021D-路径

> part 4, 4.4



## 题意理解

![在这里插入图片描述](https://img-blog.csdnimg.cn/75f2a38a3ec94927b7d8c9ea11fb0fba.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)



## 自己解法

- 10266837
- x*y=最小公倍数\*最大公约数

```c++
#include <bits/stdc++.h>
using namespace std;
const int inf = 99999999;
int e[2022][2022], dis[2022];
bool visit[2022];

int gcd(int a, int b) {
	return b == 0 ? abs(a) : gcd(b, a % b);
}

int main(){
	fill(e[0], e[0]+2022*2022, inf);
	for(int i=1;i<=2021;i++){
		for(int j=i+1;j<=2021;j++){
			if(abs(i - j)<=21){
				e[i][j] = e[j][i] = (i*j)/gcd(i,j);
			}
		}
	}
	fill(dis, dis + 2022, inf);
	dis[1] = 0;
	for(int i = 1;i <= 2021; i++){
		int min = -1, mindis = inf;
		for(int j = 1; j <= 2021; j++){
			if(dis[j] < mindis && visit[j] == false){
				min = j;
				mindis = dis[j];
			}
		}
		if(min == -1) break;
		visit[min] = true;
		for(int j = 1; j<= 2021;j++){
			if(e[min][j] != inf && visit[j] == false){
				if(dis[j] > dis[min] + e[min][j]){
					dis[j] = dis[min] + e[min][j];
				}
			}
		}
	}
	cout<<dis[2021]<<endl;
	system("pause");
	return 0;
}
```



## 大神解法

```c++

```
