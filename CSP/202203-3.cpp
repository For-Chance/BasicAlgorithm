#include <bits/stdc++.h>
using namespace std;

struct link{
	int limit;	// 额度
	int beginTime;	//	开始时间
	int duration;	// 可用额度持续时间 
	link(){}
	link(int x, int y, int z):limit(x), beginTime(y), duration(z){}
};

struct edge{
	vector<link>ls;
	getOneDayLimit(int now){
		if(ls.size() == 0)
			return 0;
		// 输入为当前时间
		int len = this->ls.size();
		int x = 0;
		for(auto it = ls.begin();it != ls.end();){
			if(now < (*it).beginTime+(*it).duration){
				x+=(*it).limit;
				it++;
			}else
				ls.erase(it);		// 同时处理过期的 
		}
		return x;
	}
	edge(){}
	edge(int x, int y, int z){
		this->ls.push_back(link(0, 0, 0));
	}
};

class Solution{
public:
	int n;
	vector<vector<edge>>ms;
	void createM(int n){
		// 初始化Machine
		this->n = n;
		ms = vector<vector<edge>>(n+1, vector<edge>(n+1));
	}
	
	void addEdge(int u, int v, int x, int z, int beginTime){
		edge E;
		E.ls.push_back(link(x, beginTime, z));
		ms[u][v] = E;
	}
	
	int searchQ(int q, int now){
		int maxLimit = 0;
		for(int i = 1;i <= n;i++){
			if(ms[q][i].getOneDayLimit(now) == 0)
				continue;
			int l = ms[q][i].getOneDayLimit(now);
			if(maxLimit < l)
				maxLimit = l;
				 
		}
		return maxLimit;
	}
	
	int getQi(int now){
		int cnt = 0;
		for(int i = 1;i <= n-1;i++)
			for(int j = i+1;j <= n;j++){
				if(searchQ(i, now) == searchQ(j, now))
					cnt++;
			}
		return cnt;
	}
	
	int getPi(int now){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(searchQ(i, now) == 0)
				cnt++;
		}
		return cnt;
	}
};

int main(){
	Solution solution;
	int n, m;
	cin >> n >> m;
	solution.createM(n);
	vector<int>result;
	for(int i = 1;i <= m;i++){
		int ki;
		cin >> ki;
		for(int j = 0;j < ki;j++){
			int u, v, x, y;
			cin >> u >> v >> x >> y;
			solution.addEdge(u, v, x, y, i);
			solution.addEdge(v, u, x, y, i);
		}
		int li;
		cin >> li;
		for(int j = 0;j < li;j++){
			int q;
			cin >> q;
			result.push_back(solution.searchQ(q, i));
		}
		// 这俩个先不管 
		int qi, pi;
		cin >> qi >> pi;
		if(qi)
			result.push_back(solution.getQi(i));
		if(pi)
			result.push_back(solution.getPi(i));
	}
	for(int i = 0;i < result.size();i++)
		cout << result[i] << endl;
	return 0;
}

