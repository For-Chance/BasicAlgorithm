#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	
	// ǰi���ַ���ǰ����������Ч�����Ӵ��ĳ���
	vector<int>dp(s.length()) ;
	
	for(int i = 0;i < s.length();i++) {
		if(s[i] == '(')
			dp[i] = 0;
		else{
			if(i - dp[i-1] >= 0 && s[i - dp[i-1]] == ')'){
				// ����û�п�������Խ������� 
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
