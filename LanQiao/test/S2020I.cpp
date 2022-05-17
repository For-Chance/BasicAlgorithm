#include <bits/stdc++.h>
using namespace std;
const long long inf = 9999999999999999;
const double mindis = 10-6;
double xA, yA, xB, yB, L;
double x1, y1, x2, y2, x3, y3;
double k1, b1, k2, b2, k3, b3;
bool op1, op2, op3;
double minx, miny, maxx, maxy;

bool inCyc(int x, int y){
	double d1 = sqrt(pow(x-xA, 2) + pow(y-yA, 2));
	double d2 = sqrt(pow(x-xB, 2) + pow(y-yB, 2));
	return d1+d2<L;
}

bool inTri(int x, int y){
	if(((k1 == inf) ? (x < b1) : (k1 * x + b1 - y < 0)) != op1) return false;
	if(((k2 == inf) ? (x < b2) : (k2 * x + b2 - y < 0)) != op2) return false;
	if(((k3 == inf) ? (x < b3) : (k3 * x + b3 - y < 0)) != op3) return false;
	return true;
}

int main(){
	cin>>xA>>yA>>xB>>yB>>L;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	k1 = (x2 - x1 == 0) ? inf : (y2 - y1)/(x2 - x1);
	k2 = (x3 - x2 == 0) ? inf : (y3 - y2)/(x3 - x2);
	k3 = (x1 - x3 == 0) ? inf : (y1 - y3)/(x1 - x3);
	b1 = (k1 == inf) ? x1 : y1 - k1 * x1;
	b2 = (k2 == inf) ? x2 : y2 - k2 * x2;
	b3 = (k3 == inf) ? x3 : y3 - k3 * x3;
	op1 = (k1 == inf) ? (x3 < b1) : (k1 * x3 + b1 - y3 < 0);
	op2 = (k2 == inf) ? (x1 < b2) : (k2 * x1 + b2 - y1 < 0);
	op3 = (k3 == inf) ? (x2 < b3) : (k3 * x2 + b3 - y2 < 0);
	
	vector<double>xx;
	xx.push_back(x1);
	xx.push_back(x2);
	xx.push_back(x3);
	sort(xx.begin(), xx.end());
	minx = xx[0];
	maxx = xx[2];
	
	vector<double>yy;
	yy.push_back(y1);
	yy.push_back(y2);
	yy.push_back(y3);
	sort(yy.begin(), yy.end());
	miny = yy[0];
	maxy = yy[2];

	double s = 0.0;
	for(double x = minx;x <= maxx; x+=0.1)
		for(double y = miny;y <= maxy; y+=0.1)
			if(inCyc(x, y) && inTri(x, y))
				s += 0.01;
	printf("%.2f\n", s);
	
	//cout<<k2 * x1 + b2 - y1<<endl;
	//cout<<k1<<" "<<b1<<" "<<op1<<endl;
	//cout<<k2<<" "<<b2<<" "<<op2<<endl;
	//cout<<k3<<" "<<b3<<" "<<op3<<endl;
	return 0;
}
