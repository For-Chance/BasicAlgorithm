#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
bool v[7][7] = {
	{0, 1, 0, 0, 0, 1, 0},
	{1, 0, 1, 0, 0, 0, 1},
	{0, 1, 0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1, 0, 0},
	{0, 0, 0, 1, 0, 1, 1},
	{1, 0, 0, 0, 1, 0, 1},
	{0, 1, 1, 0, 1, 1, 0}
};
int d[7];
void dfs(int root){
	if
}

int main(){
	for(int i = 1;i < 127;i++){
		for(int j = 6;j >= 0;j--)
			d[j] = i % 2;
		int flag = 1;
		for(int j = 0;j < 7; j++)
			if(d[j] == 1){
				fill(visit, visit + 7, false);
				dfs(j);
				break;
			}		
		cnt++;
	}
	cout<<cnt<<endl;
	return 0; 
}

// 0-127
