#include <bits/stdc++.h>
using namespace std;

string to_s(int d){
	string a = "";
	char b = '0';
	if(d < 10) a+=b;
	do{
		b = '0' + d % 10;
		a += b;
		d = d / 10; 
	}while(d != 0);
	reverse(a.begin(), a.end());
	return a;
}

int main(){
	int year, month, day;
	scanf("%4d%2d%2d", &year, &month, &day);
	int flag = 0;
	while(1){
		day++;
		if(year % 4 == 0 && year %100 != 0){
			if(month == 2){
				if(day == 29){
					day = 1;
					month++;
				}
			}else if(month == 4 || month == 6 || month == 9 || month == 11){
				if(day == 31){
					day = 1;
					month++;
				}
			}else{
				if(day == 32){
					day = 1;
					month++;
				}
			}
		}else{
			if(month == 2){
				if(day == 30){
					day = 1;
					month++;
				}
			}else if(month == 4 || month == 6 || month == 9 || month == 11){
				if(day == 31){
					day = 1;
					month++;
				}
			}else{
				if(day == 32){
					day = 1;
					month++;
				}
			}
		}
		if(month == 13){
			month = 1;
			year++;
		}
		string s = "";
		s += to_s(year);
		s += to_s(month);
		s += to_s(day);
		string res_s = s;
		reverse(res_s.begin(), res_s.end());
		if(s == res_s){
			if(flag == 0){
				cout<<s<<endl;
				flag = 1;
			}
			if(s[0] == s[2] && s[1] == s[3]){
				cout<<s<<endl;
				break;
			}
		}
	}
	return 0;
}
