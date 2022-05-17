#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	string p;
	cin>>p;
	int i = 0, j = 0;
	
	// s上的前i个字符，p上的前j个字符能否匹配
	vector<vector<bool>>dp(s.length(), vector<bool>(p.length()));
	// 初始化
	
	do{
		
	}while(i != s.length() || j != p.length());
	 
//	for(int i = 0;i < s.length();i++) {
//		for(int j = 0;j < p.length();j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
		
	if(dp[s.length()-1][p.length()-1])
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
