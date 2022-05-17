# 最长回文子串

> part 5，5.0



## 题意理解

- [5. 最长回文子串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-palindromic-substring/)



## 自己解法

- 只跑通了样例

```c++
#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
	cin>>s;
	// 第i个字符为中心，为回文子串的最长半径 
	int len = s.length();
	vector<int>dp(len, 1);
	// 奇数 
	int max = -1, maxi = -1;
	for(int i = 0;i < len;i++)
	{
		int p = 1;
		while(i - p >= 0 && i + p < len && s[i - p] == s[i + p]){
			dp[i]++;
			p++;
		};
		if(max < dp[i]){
			max = dp[i];
			maxi = i;
		}
	}
	// 偶数对称 
	int max2 = -1, max2i = -1;
	 vector<int>dp2(len-1, 0);
	 for(int i = 0;i < len-1;i++){
	 	int p = 1;
	 	while(i-p+1 >= 0 && i+p < len && s[i-p+1] == s[i+p]){
	 		dp2[i]++;
	 		p++;
		};
		if(max2 < dp2[i]) {
			max2 = dp2[i];
			max2i = i;
		}
	 }
	if(2*max-1 > 2*max2)
		cout<<s.substr(maxi - dp[maxi] + 1, 2 * dp[maxi] - 1)<<endl;
	else
		cout<<s.substr(max2i - dp2[max2i] + 1, 2 * dp2[max2i])<<endl;
	return 0;
}
```

