#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<int>share;
	vector<int>occupy;
	vector<int>pre;
	
	void build(int m){
		// 下标0不用 
		share = vector<int>(m+1, 0);
		occupy = vector<int>(m+1, 0);
		pre = vector<int>(m+1, 0);
	}
	
	int write(int id, int l, int r, int x){
		int right = -1;
		for(int i = l;i <= r;i++){
			if(occupy[i] == 0){
				share[i] = x;
				occupy[i] = id;
				pre[i] = 0;
				right = i;
			}else if(occupy[i] == id){
				share[i] = x;
				right = i;
			}else
				break;
		}
		return right;
	}
	
	// delete 是关键字 
	bool del(int id, int l, int r){
		for(int i = l;i <= r;i++)
			if(occupy[i] != id)
				return false;
		for(int i = l;i <= r;i++){
			occupy[i] = 0;
			pre[i] = id;
		}
		return true;
	}
	
	bool recover(int id, int l, int r){
		for(int i = l;i <= r;i++)
			if(occupy[i] != 0 || pre[i] != id)
				return false;
		for(int i = l;i <= r;i++){
			occupy[i] = id;
			pre[i] = 0;
		}
		return true;
	}
	
	vector<int> read(int p){
		if(occupy[p] == 0)
			return {0, 0};
		else
			return {occupy[p], share[p]};
	}
};

int main(){
	Solution solution;
	int n, m, k;
	cin >> n >> m >> k;
	solution.build(m);
	for(int i = 0;i < k;i++){
		int flag;
		cin >> flag;
		if(flag == 0){
			int id, l, r, x;
			cin >> id >> l >> r >> x;
			cout << solution.write(id, l, r, x);
		}else if(flag == 1){
			int id, l, r;
			cin >> id >> l >> r;
			bool flag = solution.del(id, l, r);
			cout << (flag ? "OK" : "FAIL");
		}else if(flag == 2){
			int id, l, r;
			cin >> id >> l >> r;
			bool flag = solution.recover(id, l , r);
			cout << (flag ? "OK" : "FAIL");
		}else if(flag == 3){
			int p;
			cin >> p;
			vector<int> res = solution.read(p);
			cout << res[0] << " " <<res[1];
		}
		cout << endl;	
	}
	return 0;
}
