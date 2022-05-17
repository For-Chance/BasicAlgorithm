#include <bits/stdc++.h>
using namespace std;

int main(){
	int max = -1, min = 101;
	double avg;
	int N;
	cin>>N;
	int s, sum = 0;
	for(int i = 0;i < N;i++)
	{
		cin>>s;
		if(max < s)
			max = s;
		if(min > s)
			min = s;
		sum += s;
	}
	avg = double(sum) / N;
	printf("%d\n%d\n%.2f\n", max, min, avg);
	return 0;
}
