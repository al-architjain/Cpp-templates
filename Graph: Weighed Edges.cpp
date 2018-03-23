#include<iostream>
#include<utility>
#include<vector>
#define ll long long
using namespace std;

class graph{
	ll nodes;
	ll edges;
	pair< pair<ll,ll>, ll> *E;
	public:
		graph(int n, int m)
		{
			nodes = n;
			edges = m;
			E = new pair<pair<ll,ll>,ll>[m+1];
		}
		
		void input()
		{
			for(ll i=1; i<=edges; i++)
			{
				cin>>a>>b>>w;
				E[i].make_pair(make_pair(a,b),w);
			}
		}
};
