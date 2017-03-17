#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include <ctime>
#define pb(x) push_back(x)
#define sz(x) x.size()
#define pii pair<int,int>
#define F first
#define S second
#define m_p make_pair
#define inf 1000000000
using namespace std;
vector<pii> g;
map<pii,int>weight;
void solve(int src,int n)
{
	int dist[n+1];
	for(int i=1;i<=n;i++)
		dist[i]=inf;
	dist[src]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<sz(g);j++)
		{
			int u=g[j].F;
			int v=g[j].S;
			if(dist[u]+weight[m_p(u,v)]<dist[v]&&dist[u]!=inf)
				dist[v]=dist[u]+weight[m_p(u,v)];
		}

	}
	for(int i=0;i<sz(g);i++)
	{
		int u=g[i].F;
		int v=g[i].S;
		if(dist[u]+weight[m_p(u,v)]<dist[v]&&dist[u]!=inf)
		{
			cout<<"contains negative cycle\n";
			break;
		}
	}
	cout<<"distances from "<<src<<"->";
	for(int i=1;i<=n;i++)
	{
			cout<<dist[i]<<" ";
	}
	cout<<endl;
	return;
}
int main()
{
    int start_s=clock();
    cout<<"Number of vertices\n";
  	int n;
  	cin>>n;
  	cout<<"enter Adjacency matrix\n";
  	int a[n+1][n+1];
  	for(int i=1;i<=n;i++)
  		for(int j=1;j<=n;j++)
  		{
  			cin>>a[i][j];
  			//a[i][j]=0;
  			//if(i!=j)
  			//a[i][j]=rand()%14;
  			if(a[i][j]!=0)
  			{
  				g.pb(m_p(i,j));
  				weight[m_p(i,j)]=a[i][j];
  			}
  		}
  	for(int i=1;i<=n;i++)
  	{
  		for(int j=1;j<=n;j++)
  			cout<<a[i][j]<<" ";
  		cout<<endl;
	  }
  	cout<<"Answer\n";
  	for(int i=1;i<=n;i++)
  		solve(i,n);
  	int stop_s=clock();
  	
	cout << "TIME: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    return 0;
}
