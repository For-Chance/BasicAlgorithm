#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;
	vector<int>tree(n);
	for(int i = 0;i < n;i++)
		cin>>tree[i];
	vector<int>weight;
	int i = 0, p = pow(2, i) - 1;
	while(p < n){
		int sum = 0;
		for(int j = pow(2,i)-1;j < pow(2,i+1)-1 && j < tree.size();j++)
			sum+=tree[j];
		weight.push_back(sum);
		i++;
		p = pow(2, i) - 1;
	}
	int max = -99999999, maxi = -1;
	for(i = 0;i < weight.size();i++){
		if(max < weight[i]){
			max = weight[i];
			maxi = i;
		}
	}
	cout<<maxi+1<<endl;
	
	return 0;
}
