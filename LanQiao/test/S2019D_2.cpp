#include <bits/stdc++.h>
using namespace std;
const int inf = 999999;
const int row = 30;
const int col = 50;
const int endpoint = row * col;
vector<string>res;
bool  visit[endpoint];
int e[endpoint][endpoint], dis[endpoint], pre[endpoint];
string s[row];

int P(int i, int j){
	return i * col + j;
}

int getPri(int d){
	if(d == -col) return 4;
	else if(d == 1) return 3;
	else if(d == -1) return 2;
	else if(d == col) return 1;
	else return 0;
}

char getChar(int d){
	if(d == -col) return 'D';
	else if(d == 1) return 'L';
	else if(d == -1) return 'R';
	else if(d == col) return 'U';
	else return 'X';
}

void dfs(int end){
	if(pre[end] != 0)
		dfs(pre[end]);
	cout<<getChar(pre[end] - end);
}

int main(){
	for(int i = 0;i < row;i++)
		cin>>s[i];
	fill(e[0], e[0] + endpoint * endpoint, inf);
	for(int i = 0;i < row;i++)
		for(int j = 0;j < col;j++)
			if(s[i][j] == '0'){
				if(i > 0)
					if(s[i-1][j] == '0') // ◊›œÚ 
						e[P(i, j)][P(i-1, j)] = e[P(i-1, j)][P(i, j)] = 1;
				if(j > 0)
					if(s[i][j-1] == '0') // ∫·œÚ 
						e[P(i, j)][P(i, j-1)] = e[P(i, j-1)][P(i, j)] = 1;
			}
	//for(int i = 0; i<endpoint;i++){
		//for(int j = 0;j<endpoint;j++)
			//cout<<e[i][j]<<" ";
		//cout<<endl;
	//}
	fill(dis, dis + endpoint, inf);
	dis[0] = 0;
	fill(pre, pre + endpoint, 0);
	fill (visit, visit + endpoint, false);
	for(int i = 0;i < endpoint;i++){
		int min = -1, mindis = inf;
		for(int j = 0;j < endpoint;j++){
			if(mindis > dis[j] && visit[j] == false){
				min = j;
				mindis = dis[j];
			}
		}
		if(min == -1) break;
		visit[min] = true;
		for(int j = 0;j < endpoint;j++)
			if(visit[j] == false && e[min][j] != inf)
				if(dis[j] > dis[min] + e[min][j]){
					dis[j] = dis[min] + e[min][j];
					pre[j] = min;
				}else if(dis[j] == dis[min] + e[min][j]){
					if(getPri(j-min) > getPri(pre[j]-min))
						pre[j] = min;
				}
	}
	dfs(endpoint - 1);
	cout<<endl;
	return 0;
}

// DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR
