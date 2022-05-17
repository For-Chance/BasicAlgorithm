# S2021A-卡片

> part 1, 1.6



## 题意理解

![在这里插入图片描述](https://img-blog.csdnimg.cn/f49b8577ed0e471c9105c353916c610f.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)



## 自己解法

- 

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

需要判断两个浮点数之间的差是否小于一个较小值（$10^{-7}$）

```c++
#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

struct Line {
  Point a, b;
  Line(Point a, Point b) {
    this->a = a;
    this->b = b;
  }
};

vector<Line> lineList;

double Dis(Point p0, Point p1) {
  return sqrt((p0.x - p1.x) * (p0.x - p1.x) + (p0.y - p1.y) * (p0.y - p1.y));
}

bool CheckPointInLine(Line x, Point p) {
  double dis[3];
  dis[0] = Dis(x.a, x.b);
  dis[1] = Dis(x.a, p);
  dis[2] = Dis(x.b, p);
  sort(dis, dis + 3);
  if (fabs(dis[0] + dis[1] - dis[2]) < 1e-5) {
    return true;
  } else {
    return false;
  }
}

bool CheckLineRepeat(Line cur) {
  for (unsigned int i = 0; i < lineList.size(); i++) {
    if (CheckPointInLine(lineList[i], cur.a) &&
        CheckPointInLine(lineList[i], cur.b)) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<Point> pointList;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
      pointList.push_back(Point(i, j));
    }
  }

  int ans = 0;
  for (unsigned int i = 0; i < pointList.size(); i++) {
    for (unsigned int j = i + 1; j < pointList.size(); j++) {
      Line curLine = Line(pointList[i], pointList[j]);
      if (!CheckLineRepeat(curLine)) {
        ans++;
        lineList.push_back(curLine);
      }
    }
  }
  printf("ans = %d\n", ans);
  return 0;
}
```

