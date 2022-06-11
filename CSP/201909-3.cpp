#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
};

int main(){
	
	Solution solution;
	string a = "sadkfjaslknv";
	for(int i = 0;i < a.length();i++)
		cout << "\\x" << int(a[i]);
	return 0;
}
