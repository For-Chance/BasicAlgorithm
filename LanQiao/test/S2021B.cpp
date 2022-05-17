#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>A, B;
	for(int x1 = 0;x1<=19;x1++){
		for(int y1 = 0;y1<=20;y1++){
			for(int x2 = 0;x2<=19;x2++){
				for(int y2 = 0; y2 <= 20; y2++){
					double a = (y2 - y1)/(x2 - x1);
					double b = (y1*x2 - y2*x1)/(x2 - x1);
					if(find(A.begin(), A.end(), a) == A.end() || find(B.begin(), B.end(), b) == B.end())
					{
						A.push_back(a);
						B.push_back(b);
					}
				}
			}
		}
	}
	cout<<A.size()<<endl;
	system("pause");
	return 0;
}
