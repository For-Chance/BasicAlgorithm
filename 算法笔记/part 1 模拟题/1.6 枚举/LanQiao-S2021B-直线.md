# S2021A-直线

> part 1, 1.6



## 题意理解

![在这里插入图片描述](https://img-blog.csdnimg.cn/678158bf5d654f4392bab8926293ee8d.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)



## 自己解法

- 3181

```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v(10);
	int i = 1;
	while(1){
		if(find(v.begin(), v.end(), 2021) != v.end()) break;
		int a = i;
		while(a != 0){
			v[a % 10]++;
			a = a / 10;
		}
		i++;
	}
	cout<<i-1<<endl;
	system("pause");
	return 0;
}
```



## 大神解法

```c++

```
