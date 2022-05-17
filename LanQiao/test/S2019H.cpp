#include <bits/stdc++.h>
using namespace std;
set<int>temp;


int main(){
	int n;
	cin>>n;
	int a;
	vector<int>m(n);
	for(int i = 0;i < n;i++){
		cin>>a;
		set<int>::iterator pos = temp.find(a);
		if(pos != temp.end()){
			do{
				if(*(++pos) != ++a) break;
			}while(pos != temp.end());
		}
		m[i] = a;
		temp.insert(a);
	}
	for(vector<int>::iterator it = m.begin();it != m.end();it++)
		cout<<*it<<" ";
	return 0;
}

// ³¬Ê±ÁËÁ½ 
