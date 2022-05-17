#include <bits/stdc++.h>
using namespace std;
bool e[22][22];
int gcd(int a, int b) {
	return b == 0 ? abs(a) : gcd(b, a % b);
}
long long cnt = 0;
void go(int node, int depth){
	if(depth == 21){
		cnt++;
		visit[node] =false;
		return;
	}
	for(int i = 1; i <= 21;i++){
		if(e[node][i] == true && visit[i] ==false){
			visit[i] = true;
			go(i, depth+1);
		}
	}
	visit[node] = false;
	return;
}

int main(){
	fill(e[0], e[0]+22*22, false);
	for(int a = 1;a <= 21;a++){
		for(int b = a+1;b <= 21;b++){
			if(gcd(a, b) == 1)
				e[a][b] = e[b][a] = true;
		}
	}
	go(1, 1);
	cout<<cnt<<endl;
	return 0;
}
