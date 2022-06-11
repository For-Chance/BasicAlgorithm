#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	bool isRight(string eq){
		unordered_map<string, int>m1;
		int i = 0;
		int len = eq.length();
		while(eq[i] != '='){
			// 获得元素
			string str = eq.substr(i, 1);
			int num =  -1;
			char nextChar = eq[i+1];
			if(str == "+"){
				i++;
				continue;
			} else if(isupper(nextChar)){
				str = eq[i];
				num = 1;
				i++;
			} else if(islower(nextChar)){
				str = eq.substr(i, 2); 
				i+=2;
			} else
				i++;
			// 只有后一个字母不是大写字母或者加号的才要看数字 
			if(num != 1){
				int dis = 0;
				while(isdigit(eq[i])){
					dis++;
					i++; 
				}
				num = stoi(eq.substr(i-dis, dis));
			}
			auto pos = m1.find(str);
			if(pos == m1.end())
				m1[str] = num;
			else
				pos->second += num;
		}
		i++;
		while(i < len){
			// 获得元素
			string str = eq.substr(i, 1);
			int num =  -1;
			char nextChar;
			if(i+1 < len)
				nextChar = eq[i+1];
			else
				nextChar = 'D';
			if(str == "+"){
				i++;
				continue;
			} else if(isupper(nextChar)){
				str = eq[i];
				num = 1;
				i++;
			} else if(islower(nextChar)){
				str = eq.substr(i, 2); 
				i+=2;
			} else
				i++;
			// 只有后一个字母不是大写字母或者加号的才要看数字 
			if(num != 1){
				int dis = 0;
				while(isdigit(eq[i])){
					dis++;
					i++; 
				}
				num = stoi(eq.substr(i-dis, dis));
			}
			auto pos = m1.find(str);
			if(pos == m1.end())
				return false;
			else{
				pos->second -= num;
				if(pos->second < 0)
					return false;
				else if(pos->second == 0)
					m1.erase(pos);
			}
		}
		if(m1.size() == 0)
			return true;
		return false;
	}
};

int main(){
	Solution solution;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		string equation;
		cin >> equation;
		if(solution.isRight(equation))
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
	}
	return 0;
}

/*
11
H2+O2=H2O
2H2+O2=2H2O
H2+C12=2NaCl
H2+C12=2HC1
CH4+202=CO2+2H2O
CaC12+2AgNO3=Ca(NO3)2+2AgCl
3Ba(0H)2+2H3P04=6H2O+Ba3(P04)2
3Ba(0H)2+2H3P04=Ba3(P04)2+6H20
4Zn+18HN03=4Zn(N03)2+NH4N03+3H20
4AU+8NaCN+2H20+02=4Na (Au(CN)2)+4NaOH
Cu+AS=CS+Au
*/

