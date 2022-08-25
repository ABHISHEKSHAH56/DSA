//get connected components of graph 
#include<bits/stdc++.h>
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

void checkhaspath(int node,vector<Edges*> adj[],vector<bool>&visit ,vector<int> &arr)
{
    
    visit[node]=true;
    arr.push_back(node);
    for(auto it:adj[node])
    { 
        if(!visit[it->n]) checkhaspath(it->n,adj,visit,arr);
    }
    return ;
}



int main()
{
    int v,e;
    cin>>v>>e;
    vector<Edges *> adj[v+1];
    for(int i=1; i<=v; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back(new Edges(x,y,z));
        //for undireted 
        adj[y].push_back(new Edges(y,x,z));
    }
    
    vector<bool>visited(v+1);
    int count=0;
    vector<vector<int>>allvertex;
    for(int i=1; i<=v; i++)
    {
        count++;
        vector<int>arr;
        checkhaspath(i,adj,visited,arr);
        allvertex.push_back(arr);
        
    }
    

}