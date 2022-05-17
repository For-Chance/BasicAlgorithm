#include <bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int dfs(int root){
	if(v[root].size() == 0)
		return 1;
	else{
		int maxDepth = 0;
		vector<int>depth;
		for(int i = 0;i < v[root].size();i++){
			int depth = dfs(v[root][i]);
			if(maxDepth < depth)
				maxDepth = depth;
		}
		return maxDepth + v[root].size();
	}
}

int main(){
	int N;
	cin>>N;
	if(N == 1) cout<<1<<endl;
	for(int i = 2;i <= N;i++){
		int a;
		cin>>a;
		v[a].push_back(i);
	}
	cout<<dfs(1) - 1<<endl;
	return 0;
}
