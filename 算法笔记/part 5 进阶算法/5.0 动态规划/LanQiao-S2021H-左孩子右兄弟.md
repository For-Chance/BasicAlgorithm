# S2021H-左孩子右兄弟

> part 5, 5.0s



## 题意理解

![在这里插入图片描述](https://img-blog.csdnimg.cn/bfd399e488a544958e18067ccce793e7.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

![在这里插入图片描述](https://img-blog.csdnimg.cn/ca4fbfaa53cc4d96b86a34808e7e2a6c.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

![在这里插入图片描述](https://img-blog.csdnimg.cn/d182cf0f13a64198ba5e7f7eb33b0cd5.jpg#pic_center)



## 自己解法

- 一种想法，dfs实现树形dp，关键是第15行


```c++
#include <bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int dfs(int root){
	if(v[root].size() == 0)
		return 1;
	else{
		int maxDepth = 0;
		vector<int>depth;
		for(int i = 0;i < v[root].size();i++){
			int depth = dfs(v[root][i]);
			if(maxDepth < depth)
				maxDepth = depth;
		}
		return maxDepth + v[root].size();
	}
}

int main(){
	int N;
	cin>>N;
	if(N == 1) cout<<1<<endl;
	for(int i = 2;i <= N;i++){
		int a;
		cin>>a;
		v[a].push_back(i);
	}
	cout<<dfs(1) - 1<<endl;
	return 0;
}
```



## 大神解法

```c++
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100052;
int fa[maxn], n;
vector<int> u[maxn];

int dfs(int x) {
  int ret = 1;

  for (int i = 0; i < u[x].size(); i++) {
    int temp = 1 + dfs(u[x][i]) + u[x].size() - 1;
    ret = max(temp, ret);
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &fa[i]);
    u[fa[i]].push_back(i + 2);
  }

  printf("%d\n", dfs(1) - 1);
  return 0;
}
```
