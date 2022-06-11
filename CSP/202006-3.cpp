#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	bool isVoidLine(string line){
		if(line.length() == 0) 
			return true;
		for(int i = 0;i < line.length();i++)
			if(line[i] != ' ')
				return false;
		return true;
	}
	
	bool isProject(string line){
		if(line[0] == '*' && line[1] == ' ')
			return true;
		return false;
	}
	
	bool isProjectInclude(string line){
		if(isProject(line))
			return true;
		if(!isVoidLine(line))
			if(line[0] == ' ' && line[1] == ' ')
				return true;
		return false;
	}
	
	bool isPar(string line){
		if(isVoidLine(line) || isProject(line))
			return false;
		return true;
	}
	
	string clearStr(string line){
		int end = line.length()-1;
		int i;
		for(i = 0;i <= end;i++)
			if(line[i] != ' ')
				break;
		for(;end > i ;end--)
			if(line[end] != ' ')
				break;
		return line.substr(i, end-i+1);
	}
	
	int getLines(vector<string>& text, int n){
		int ls = text.size();
		vector<string>res;
		for(int i = 0;i < ls;){
			if(isProject(text[i])){
				// 是项目 
				if(res.size() != 0 && (!isVoidLine(res.back())))
					res.push_back("");
				int len = 1;
				string ProStr = clearStr(text[i]);
				while(i+1 < ls && isProjectInclude(text[++i])){
					len++;
					string str = text[i].substr(2, text[i].length()-2+1);
					str = clearStr(str);
					ProStr += " " + str;
				} 
				if(i+1 == ls)
					i++;
				// 插入 
				for(int j = 0;j < ProStr.length();){
					while(ProStr[j] == ' '){
						j++;
					}
					if(j+n-1 < ProStr.length()){
						res.push_back(" * " + ProStr.substr(j, n));
						j += n;
						cout << res.back() << endl;
					}else{
						res.push_back(" * " + ProStr.substr(j, ProStr.length()-j));
						j = ProStr.length();
						cout << res.back() << endl;
					}
				}
			}else if(isVoidLine(text[i])){
				// 空行 
				res.push_back("");
				i++;
				continue;
			}else{
				// 是段落 
				if(res.size() != 0 && (!isVoidLine(res.back())))
					res.push_back("");
				int len = 1;
				string ParStr = clearStr(text[i]);
				while(i+1 < ls && isPar(text[++i])){
					len++;
					// 多行用空格连接 
					// 先去除首尾空格 
					text[i] = clearStr(text[i]);
					ParStr += " " + text[i];
				}
				if(i+1 == ls)
					i++;
				// 插入 
				for(int j = 0;j < ParStr.length();){
					while(ParStr[j] == ' '){
						j++;
					}
					if(j+n-1 < ParStr.length()){
						res.push_back(ParStr.substr(j, n));
						j += n;
					}else{
						res.push_back(ParStr.substr(j, ParStr.length()-j));
						j = ParStr.length();
					}
				}
			}
		}
		for(int i = 0;i < res.size();i++)
			cout << res[i] << endl;
		return res.size();
	}
};

int main(){
	Solution solution;
	int n;
	cin >> n;
	cin.ignore();
	vector<string>text;
	string line;
	while(getline(cin, line)){
		if(solution.isVoidLine(line) && text.size() == 0)
			continue;
		text.push_back(line);
	}
	int ls = text.size()-1;
	while(solution.isVoidLine(text[ls])){
		text.pop_back();
		ls--;
	}
	cout << solution.getLines(text, n);
	return 0;
}

/*
10
CSP
       
CSP is   
a real realrealrealrealreal
       competition.

Come   and   join   us

10
* CSP
     
*   CSP is
  * a real
     competition.
* 
  * Come!   and   join.
*Te1:
* 12345
* 

*/

