# S2021G-异或数列

> part 0 博弈



## 题意理解

![在这里插入图片描述](https://img-blog.csdnimg.cn/1bb23efd9c224d5d8bfb38efa2c536be.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

![在这里插入图片描述](https://img-blog.csdnimg.cn/336d9a4b67674bdbb91a8833821f537d.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)



## 自己解法

- 没过


```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int i = 0;i<T;i++){
		int n;
		vector<long long>X;
		cin >> n;
		for(int j = 0; j < n;j++) {
			int a;
			cin>>a;
			X.push_back(a);
		}
		int a = 0, b = 0;
		while(1){
			int max = 0;
			vector<long long>::iterator maxj = X.begin();
			for(vector<long long>::iterator j = X.begin(); j != X.end();j++){
				if(max < ((*j) ^ a)){
					max = ((*j) ^ a);
					maxj = j;
				}
			}
			a = max;
			X.erase(maxj);
			if(X.size() == 0) break;
			
			max = 0;
			maxj = X.begin();
			for(vector<long long>::iterator j = X.begin(); j != X.end();j++){
				if(max < ((*j) ^ b)){
					max = ((*j) ^ b);
					maxj = j;
				}
			}
			b = max;
			X.erase(maxj);
			if(X.size() == 0) break;
		}
		if(a > b)
			cout<<1<<endl;
		else if (a == b)
			cout<<0<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
```



## 大神解法

![image-20220406200016167](C:/Users/mechrevo/AppData/Roaming/Typora/typora-user-images/image-20220406200016167.png)

```c++
#include <bits/stdc++.h>
using namespace std;

int num[50] = {0};

void add(int x) {
  int cnt = 0;
  while (x > 0) {
    if (x & 1) {
      num[cnt]++;
    }
    cnt++;
    x >>= 1;
  }
}
int main() {
  int T, n, a, b;
  scanf("%d", &T);
  while (T--) {
    int xorSum = 0, temp;
    memset(num, 0, sizeof(num));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      add(temp);
      xorSum ^= temp;
    }

    if (xorSum == 0) {
      printf("0\n");
      continue;
    }

    int ans = 0, pos = 0;
    for (int i = 30; i >= 0; i--) {
      if (num[i] & 1) {
        pos = i;
        break;
      }
    }

    if (n & 1 || num[pos] == 1) {
      printf("1\n");
    } else {
      printf("-1\n");
    }
  }
  return 0;
}

```
