#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int i = 0;i<T;i++){
		int n;
		vector<long long>X;
		cin >> n;
		for(int j = 0; j < n;j++) {
			int a;
			cin>>a;
			X.push_back(a);
		}
		int a = 0, b = 0;
		while(1){
			int max = 0;
			vector<long long>::iterator maxj = X.begin();
			for(vector<long long>::iterator j = X.begin(); j != X.end();j++){
				if(max < ((*j) ^ a)){
					max = ((*j) ^ a);
					maxj = j;
				}
			}
			a = max;
			X.erase(maxj);
			if(X.size() == 0) break;
			
			max = 0;
			maxj = X.begin();
			for(vector<long long>::iterator j = X.begin(); j != X.end();j++){
				if(max < ((*j) ^ b)){
					max = ((*j) ^ b);
					maxj = j;
				}
			}
			b = max;
			X.erase(maxj);
			if(X.size() == 0) break;
		}
		if(a > b)
			cout<<1<<endl;
		else if (a == b)
			cout<<0<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
