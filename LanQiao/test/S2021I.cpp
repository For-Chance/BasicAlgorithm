#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int leftSum = 0, rightSum = 0;
	for(int i = 0;i < s.length();i++)
		if(s[i] == '(')
			leftSum++;
	
	return 0;
}
