# 最长有效括号

> part 5，5.0



## 题意理解

- [[32. 最长有效括号 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-valid-parentheses/)](https://leetcode-cn.com/problems/longest-palindromic-substring/)



## 自己解法

- 只跑通了样例

```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	
	// 前i个字符的前面包含的最长有效括号子串的长度
	vector<int>dp(s.length()) ;
	
	for(int i = 0;i < s.length();i++) {
		if(s[i] == '(')
			dp[i] = 0;
		else{
			if(i - dp[i-1] >= 0 && s[i - dp[i-1]] == ')'){
				// 这里没有考虑数组越界的问题 
				dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
			}
				
		}
	}
	for(int i = 0;i < s.length();i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	cout<<dp[s.length() - 1]<<endl;
	return 0;
}
```

