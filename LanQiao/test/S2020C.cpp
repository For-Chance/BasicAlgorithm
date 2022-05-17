#include <bits/stdc++.h>
using namespace std;

int main(){
	int a[100][100];
	int x = 1, y = 1;
	int isUp = 1;
	for(int i = 1;i<=1000;i++){
		a[x][y] = i;
		if(y == 1 && isUp == 1){
			x++;
			isUp = 0;
		}else if(x == 1 && isUp == 0){
			y++;
			isUp = 1;
		}else{
			if(isUp){
				x++;
				y--;
			}else{
				x--;
				y++;
			}
		}
	}
	for(int i = 1; i<21;i++){
		for(int j = 1;j<21;j++)
			cout<<a[j][i]<<" ";
		cout<<endl;
	}
	return 0;
}

// 761
