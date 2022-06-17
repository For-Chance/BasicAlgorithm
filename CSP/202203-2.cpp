#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	unordered_map<int, set<int>>map;
	for(int i = 0;i < n;i++){
		int t, c;
		cin >> t >> c;
		if(map.find(t) == map.end())
			map[t] = {c};
		else
			map[t].insert(c);
	}
	for(int i = 0;i < m;i++){
		int q;
		cin >> q;
		int cnt =  0;
		for(auto it = map.begin();it != map.end();it++){
			int x = it->second.size();
			int j=0;
			for(auto iit = it->second.begin();iit != it->second.end();iit++){
				if(it->first >= q+k && it->first <= q+k+*iit-1)
					break;
				j++;
			}
//			cout << "й╠©л" << it->first << "сп" << x-j+1 << "╦Ж" <<endl; 
			cnt += x-j;	
		}
		cout << cnt << endl;
	}
	return 0;
}

