#include <bits/stdc++.h>
using namespace std;

struct Door{
	string name;
	vector<string>input; 
	int value;
};

class Solution{
public:
	// id 对应 值 
	unordered_map<int, int>input_map;
	void CreateInput(int M){
		for(int i = 1;i <= M;i++)
			input_map[i] = 0;
	}
	
	// id 对应 类 
	unordered_map<int, Door>door_map;
	void CreateDoor(Door &d, int &id){
		door_map.insert(make_pair(id, d));
	}
	
	bool isLoop = false;
	vector<int> getRes(vector<int>& inputSIGN, vector<int>& outputDoor){
		int M = inputSIGN.size();
		// 输入赋值 
		for(int i = 1;i <= M;i++)
			input_map[i] = inputSIGN[i-1];
		cout << "输入为" << endl;
		for(auto it = input_map.begin();it != input_map.end();it++)
			cout<< "id:" << it->first << " " << "value:" << it->second<<endl; 
		// 循环之前重置状态
		for(auto it = door_map.begin();it != door_map.end();it++)
			it->second.value = -1;
		// 一顿操作
		execute();
		// 对应输出
		if(isLoop)
			return {};
		int x = outputDoor.size();
		vector<int>res(x);
		for(int i = 0;i < x;i++){
			res[i] = door_map[outputDoor[i]].value;
			cout << res[i] << " ";
		}
		cout << endl;
	}
	
	void execute(){
		int N = door_map.size();
		vector<bool> visit(N+1, false);
		// 深度优先赋值
		// visit == true 的门的输出不能重新成为输入
		for(auto it = door_map.begin();it != door_map.end();it++){
			if(visit[it->first] != true){
				vector<bool> loopvisit(N+1, false);
				dfs(it->first, it->second, visit, loopvisit);
			}
		} 
	}
	
	void dfs(int id, Door &d, vector<bool> &visit, vector<bool> &loopvisit){
		visit[id] = true; 
		loopvisit[id] = true;
		for(auto in = d.input.begin();in != d.input.end();in++){
			// 循环看输入
			int val = getValue (*in);
			if(val == -1){	// 表示没有赋值
				int in_id = getId(*in);
				if(loopvisit[in_id] == false && isLoop == false)
					dfs(in_id, door_map[in_id], visit, loopvisit);
				else{
					isLoop = true;
					return;
				}
			}	 
		}
		if(!isLoop)
			assign(d);
	}
	
	int getValue(string name){
		if(name[0] == 'I')
			return input_map[getId(name)];
		else
			return door_map[getId(name)].value;
	}
	
	int getId(string name){
		return stoi(name.substr(1, name.length() - 1));
	}	
	
	void assign(Door &d){
		int x = d.input.size();
		if(d.name == "NOT"){
			if(getValue(d.input[0]) == 0)
				d.value = 1;
			else
				d.value = 0;
		}else if(d.name == "AND"){
			bool flag = false;	// 表示是否存在0 
			for(int i = 0;i < x;i++)
				if(getValue(d.input[i]) == 0)
					flag = true;
			if(flag)
				d.value = 0;
			else
				d.value = 1;
		}else if(d.name == "OR"){
			bool flag = false;	// 表示是否存在1
			for(int i = 0;i < x;i++)
				if(getValue(d.input[i]) == 1)
					flag = true;
			d.value = (flag ? 1 : 0); 
		}else if(d.name == "XOR"){
			int nowVal = getValue(d.input[0]);
			for(int i = 1;i < x;i++)
				nowVal = (nowVal ^ getValue(d.input[i]));
			d.value = nowVal;
		}else if(d.name == "NAND"){
			bool flag = false;	// 表示是否存在0 
			for(int i = 0;i < x;i++)
				if(getValue(d.input[i]) == 0)
					flag = true;
			if(flag)
				d.value = 1;
			else
				d.value = 0;
		}else if(d.name == "NOR"){
			bool flag = false;	// 表示是否存在1
			for(int i = 0;i < x;i++)
				if(getValue(d.input[i]) == 1)
					flag = true;
			d.value = (flag ? 0 : 1); 
		}
	}
};

int main(){
	Solution solution;
	int Q;
	cin >> Q;
	for(int i = 0;i < Q;i++){
		int M, N;
		cin >> M >> N;
		solution.CreateInput(M);
		for(int j = 1;j <= N;j++){
			Door d;
			cin >> d.name;
			int x;
			cin >> x;
			d.input = vector<string>(x);
			for(int k = 0;k < x;k++)
				cin >> d.input[k];
			d.value = -1;		// 表示尚未赋值 
			solution.CreateDoor(d, j);
		}
		// 第二部分 
		int S;
		cin >> S;
		vector<vector<int>>result(S);
		vector<vector<int>>inputSIGN(S, vector<int>(M));
		for(int j = 0;j < S;j++)
			for(int k = 0;k < M;k++)
				cin >> inputSIGN[j][k];
		vector<vector<int>>outputDoors(S);
		for(int j = 0;j < S;j++){
			int x;
			cin >> x;
			outputDoors[j] = vector<int>(x);
			for(int k = 0;k < x;k++)
				cin >> outputDoors[j][k];
		}
		// 结果与输出 
		for(int j = 0;j < S;j++){
			result[j] = solution.getRes(inputSIGN[j], outputDoors[j]);
			if(result[j].size() == 0){
				cout << "LOOP" << endl;
				break;
			}
		}
		if(result.size() != S)
			continue;
		for(int j = 0;j < result.size();j++){
			for(int k = 0;k < result[j].size()-1;k++)
				cout << result[j][k] << " ";
			cout << result[j][result[j].size()-1] << endl;
		}
			
	}
	return 0;
}

