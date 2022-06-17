#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<bool>a(n, false);
	a[0] = true;
	int cnt = 0;
	for(int i = 0;i < k;i++){
		int left, right;
		cin >> left >> right;
		if(a[right] == false){
			cnt++;
		}
		a[left] = true;
	}
	cout << cnt;
	return 0;
}

