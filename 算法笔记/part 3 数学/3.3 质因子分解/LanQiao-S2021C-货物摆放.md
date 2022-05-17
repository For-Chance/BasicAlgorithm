# S2021C-货物摆放

> part 3, 3.3



## 题意理解

![在这里插入图片描述](https://img-blog.csdnimg.cn/e84be8620e6f429887fbd9956370e6a9.jpg?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oiR55qE56iL5bqP6LeR5b-r5b-r,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)



## 自己解法

- 

```python
 input = 2021041820210418
z = []
i = 2;
while input != 1:
    while input % i == 0:
        z.append(i)
        input = int(input / i)
    i += 1
print(z)
```

[2, 3, 3, 3, 17, 131, 2857, 5882353]



## 大神解法

```c++

```
