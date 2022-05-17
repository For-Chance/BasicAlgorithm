#include <bits/stdc++.h>
using namespace std;
multimap<int, int> lists;
map<int, int>mai, Pri;


int main(){
	int n, m, t;
	cin>>n>>m>>t;
	for(int i = 0;i < m;i++) {
		int ts, id;
		cin>>ts>>id;
		lists.insert(make_pair(ts, id));
	}
	multimap<int, int>::iterator it = lists.begin();
	for(int i = 1;i <= n;i++)
		mai.insert(make_pair(i, 0));
	for(int i = 1;i <= t;i++){
		while(it->first == i && it != lists.end()){
			int cnt = 0;
			
			mai[it->second] += 3;
			it++;
		}
		for(int j = 1;j <= mai.size();j++){
			if(mai[j] > 0) 
				mai[j]--;
			if(mai[j] > 5)
				Pri.insert(make_pair(j, mai[j]));
			if(mai[j] == 3)
				Pri.erase(j);
		}
		for(int j = 1;j <= mai.size();j++){
			cout<<endl;
			cout<<j<<" "<<mai[j];
		}
		cout<<endl;
	}
	cout<<Pri.size()<<endl;
	return 0;
}
