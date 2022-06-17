#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int getSolution(vectro<int>& blocks){
		// 暴力
		int n = blocks.size();
		// 先做划分
		// 最多划分 n-2 刀
		for(int i = 0;i <= n-2;i++){
			// 分割出n-i个数组
			 
			 
		} 
	}
};

int main(){
	int n;
	cin >> n;
	vector<int>blocks(n);
	for(i = 0;i < n;i++)
		cin >> blocks[i];
	cout << "- 输入为：" << endl;
	for(int i = 0;i < n;i++) 
		cout << blocks[i] << " ";
	Solution solution;
	cout << solution.getSolution(blocks);
	return 0;
}

