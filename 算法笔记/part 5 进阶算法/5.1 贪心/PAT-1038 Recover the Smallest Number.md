# 1057 Stack

> part 5, 5.1



## 题意理解

- 感觉就是用vector存取数据就行吧，用一个指针指针p指着中间位置就行，
  - push->push_back，每push两次就p++
  - pop->erase(--v.end())，每pop两次就p--
  - peek->*p

- 很好，我想的太简单了，上面的思想是错的，并没有考虑排序！

### Sample Input:

```in
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
```

### Sample Output:

```out
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
```



## 自己解法

- 

```c++

```



## 大神解法

- 柳神


```c++

```

