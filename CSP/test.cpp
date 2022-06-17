#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+10;

struct Node
{
    int val;
    int pre;
    int id;
}node[N];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    while(k--)
    {
        int op; cin>>op;
        int id,l,r,x,p;
        if(op==0)
        {
            cin>>id>>l>>r>>x;
            int i=l;
            for(;i<=r;i++)
            {
                if(node[i].id==0 || node[i].id==id)
                {
                    node[i].val=x;
                    node[i].id=id;
                }
                else break;
            }
            if(i==l) cout<<-1<<endl;
            else cout<<i-1<<endl;
        }
        else if(op==1)
        {
            cin>>id>>l>>r;
            int f=1;
            for(int i=l;i<=r;i++)
            {
                if(node[i].id!=id)
                {
                   f=0; break;
                }
            }
            if(f==0) cout<<"FAIL"<<endl;
            else
            {
                cout<<"OK"<<endl;
                for(int i=l;i<=r;i++)
                {
                    node[i].pre=id;
                    node[i].id=0;
                }
            }
        }
        else if(op==2)
        {
            cin>>id>>l>>r;
            int f=1;
            for(int i=l;i<=r;i++)
            {
                if(!(node[i].id==0 && node[i].pre==id))
                {
                    f=0; break;
                }
            }
            if(f==0) cout<<"FAIL"<<endl;
            else
            {
                cout<<"OK"<<endl;
                for(int i=l;i<=r;i++)  node[i].id=id;
            }
        }
        else if(op==3)
        {
            cin>>p;
            if(node[p].id==0) cout<<0<<" "<<0<<endl;
            else cout<<node[p].id<<" "<<node[p].val<<endl;
        }
        
        for(int i = 1;i <= m;i++){
        	cout << node[i].id << "\t";
		}
		cout << endl;
		for(int i = 1;i <= m;i++){
        	cout << node[i].pre << "\t";
		}
		cout << endl;
		for(int i = 1;i <= m;i++){
        	cout << node[i].val << "\t";
		}
		cout << endl;
    }
    return 0;
}


