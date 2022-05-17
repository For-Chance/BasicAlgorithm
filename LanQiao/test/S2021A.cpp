#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v(10);
	int i = 1;
	while(1){
		if(find(v.begin(), v.end(), 2021) != v.end()) break;
		int a = i;
		while(a != 0){
			v[a % 10]++;
			a = a / 10;
		}
		i++;
	}
	cout<<i-1<<endl;
	system("pause");
	return 0;
}
