#include<iostream>
#include<vector>
#define ll long long
using namespace std;

struct node{
	ll level;
	vector<ll> adj;
};
class graph{
	ll edges;
	ll nodes;
	node* V;
	public:
		graph(int N, int M)
		{
			nodes = N;
			edges = M;
			V = new node[N+1];
		}
		void add_edge(ll a, ll b)
		{
			V[a].adj.push_back(b);
			V[b].adj.push_back(a);
		}
		void input()
		{
			for(ll i=0;i<M;i++)
			{
				cin>>a>>b;
				add_edge(a,b);
			}
		}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,m;
	cin>>n>>m;
	graph obj(n,m);
	obj.input();
	
	return 0;
}
