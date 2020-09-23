

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define p_q priority_queue
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

#define oint pair<int,int>
class Graph
{
private: 
	map<oint, list<oint> > m1;

public:
	void addEdge(int i,int j,int n,int m)
	{
		oint p = mp(i,j);

		if(i+2 < n)
		{
			if(j+1 < m)
				m1[p].pb({i+2,j+1});
			if(j-1 >= 0)
				m1[p].pb({i+2,j-1});
		}

		if(i-2 >= 0)
		{
			if(j+1 < m)
				m1[p].pb({i-2,j+1});
			if(j-1 >= 0)
				m1[p].pb({i-2,j-1});
		}

		if(i+1 < n)
		{
			if(j+2 < m)
				m1[p].pb({i+1,j+2});
			if(j-2 >= 0)
				m1[p].pb({i+1,j-2});
		}

		if(i-1 >= 0)
		{
			if(j+2 < m)
				m1[p].pb({i-1,j+2});
			if(j-2 >= 0)
				m1[p].pb({i-1,j-2});
		}
		return ;
	}

	int bfs(int s1,int s2,int e1,int e2,int n,int m)
	{
		oint src = {s1,s2};
		oint dest = {e1,e2};

		map<oint, bool> vis;
		map<oint, int> dist;

		queue<oint> q;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				vis[{i,j}] = false;
				dist[{i,j}] = INT_MAX;
			}
		}

		q.push(src);
		vis[src] = true;
		dist[src] = 0;

		while(!q.empty())
		{
			oint p = q.front();
			q.pop();
			for(auto child : m1[p])
			{
				if(!vis[child])
				{
					vis[child] = true;
					dist[child] = dist[p] + 1;
					q.push(child);
				}
			}
		}

		int distance = dist[dest];

		if(distance == INT_MAX)
			distance = -1;

		return distance;
	}

};


int main()
{
	fast_io;

	int n,m;
	cin>>n>>m;
	int s1,s2,e1,e2;
	cin>>s1>>s2>>e1>>e2;

	Graph g;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			g.addEdge(i,j,n,m);
		}
	}

	s1--,s2--,e1--,e2--;

	cout<<g.bfs(s1,s2,e1,e2,n,m)<<endl;

return 0;
}