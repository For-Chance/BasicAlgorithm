#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	unordered_set<int>map;
	int T = 0, D = 0, E = 0;
	for(int i = 0;i < n;i++){
		int m;
		cin >> m;
		int cnt;
		cin >> cnt;
		for(int j = 1;j < m;j++){
			int a;
			cin >> a;
			if(a <= 0)
				cnt+=a;
			else{
				if(cnt != a){
					map.insert(i);
				}
				cnt = a;
			}
		}
		T += cnt;
	}
	D = map.size();
	for(auto it = map.begin();it != map.end();it++){
		int a = *it;
		if(map.find((a+1 +n)%n) != map.end() && map.find((a-1+n)%n) != map.end())
			E++;
	}
	cout << T << " " << D << " " << E;
	return 0;
} 


/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0

5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0

*/
