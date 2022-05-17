#include <bits/stdc++.h>
using namespace std;
int dp[1011][1011];
int main(){
	int i, j;
	for(i = 1; i <= 1010; i++)
		dp[i][0] = 1;
	for(i = 1;i<=1010;i++){
		for(j = 1;j<=i;j++) {
			if(j == i){
				dp[i][j] = dp[i][j - 1];
			} else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 2020;
			}
		}
	}
	cout<<dp[1010][1010]<<endl;
	return 0;
}
