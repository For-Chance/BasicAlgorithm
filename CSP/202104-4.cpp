#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int getSolution(vectro<int>& blocks){
		// ����
		int n = blocks.size();
		// ��������
		// ��໮�� n-2 ��
		for(int i = 0;i <= n-2;i++){
			// �ָ��n-i������
			 
			 
		} 
	}
};

int main(){
	int n;
	cin >> n;
	vector<int>blocks(n);
	for(i = 0;i < n;i++)
		cin >> blocks[i];
	cout << "- ����Ϊ��" << endl;
	for(int i = 0;i < n;i++) 
		cout << blocks[i] << " ";
	Solution solution;
	cout << solution.getSolution(blocks);
	return 0;
}

