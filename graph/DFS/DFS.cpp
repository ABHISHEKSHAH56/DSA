//graph --have lots have componet 
#include <bits/stdc++.h>
using namespace std;

class Edges{
    public:
        int s;
        int n;
        int w;
        Edges(int s,int n,int w )
        {
            this->s=s;
            this->n=n;
            this->w=w;
        }
};


void dfs(int node,vector<bool>& visit,vector<int> adj[],vector<int>&dfsstore)
{

    dfsstore.push_back(node);
    visit[node]=true;
    for(auto it: adj[node])
    {
        if(!visit[node]){
            dfs(it,visit,adj,dfsstore);
        }
    }
}

int main() {
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<int> adj[n+1]; 
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
    vector<int>arr;
    vector<bool>visit(m+1);
    for(int i=1; i<=m; i++)
    {
        if(visit[i])
        {
            dfs(i,visit,adj,arr);
        }
    }
	return 0;
}
//-----------------iterative------dfs------------>
//heap me space kam hota hai !! 

//same like bfs 

