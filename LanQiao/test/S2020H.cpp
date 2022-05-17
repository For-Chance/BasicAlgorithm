#include <bits/stdc++.h> 
#include <time.h>
using namespace std;

int getSingle(string s){
	map<char, int>m;
	int cnt = 0, sum = 0;
	for(int i = 0;i < s.length();i++)
	{
		m[s[i]]++;
		if(m[s[i]] == 1){
			cnt++;
		}
		else if(m[s[i]] == 2){
			cnt--;
		}
		sum += cnt;
	}
	return sum;
}

int main(){
	string s;
	cin >> s;
	clock_t begin, end;
	begin = clock();
	int sum = 0;
	int len = s.length();
	for(int i = 0;i < len;i++){
		sum += getSingle(s.substr(i, len-i));
	}
	cout<<sum<<endl;
	end = clock();
	cout<<"运行时间:"<<(double)(end-begin)/CLOCKS_PER_SEC<<endl; 
	return 0;
}
