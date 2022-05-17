#include <bits/stdc++.h>
using namespace std;
int v[30][50];
vector<string>res;
int row = 4, col = 6;

char getchar(int a){
	if(a == 1) 
		return 'D';
	else if(a == 2) 
		return 'L';
	else if(a == 3) 
		return 'R';
	else if(a == 4) 
		return 'U';
	else return 'x';
}

string getstring(long long s){
	string str = "";
	do{
		str += getchar(s % 5);
		s = s / 5;
	}while(s != 0);
	return str;
}

void dfs(int x, int y, long long s, int step){
	if(x == (col - 1) && y == (row - 1)){
		string ss = getstring(s);
		res.push_back(ss);
		return;
	}
	v[y][x] = step;
	int t;
	if((v[y+1][x] > step || v[y+1][x] == 0) && y < row-1){
		t = pow(5, step - 1);
		dfs(x, y+1, s+t, step+1);
	}
	if((v[y][x-1] > step || v[y][x-1] == 0) && x > 0){
		t = 2 * pow(5, step - 1);
		dfs(x-1, y, s+t, step+1);
	}
	if((v[y][x+1] > step || v[y][x+1] == 0) && x < col-1){
		t = 3 * pow(5, step - 1);
		dfs(x+1, y, s+t, step+1);
	}
	if((v[y-1][x] > step || v[y-1][x] == 0) && y > 0){
		t = 4 * pow(5, step - 1);
		dfs(x, y-1, s+t, step+1);
	}
	return;
}

bool cmp(string a, string b){
	return a.length() != b.length() ? a.length() < b.length() : a.compare(b) < 0;
}

int main(){
	for(int i = 0;i < row;i++){
		string s;
		cin>>s;
		for(int j = 0;j < col;j++){
			if(s[j] == '0')
				v[i][j] = 0;
			else
				v[i][j] = 1;
		}
	}
	dfs(0,0,0,1);
	sort(res.begin(), res.end(), cmp);
	for(int i = 0;i < res.size();i++) 
		cout<<res[i]<<endl;
	return 0;
}

// 忙活了一晚上，实际上这个应该要用 
