//r m* w a*

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

bool isgraphcycle(vector<Edges*> adj[],int src ,vector<bool> & visit)
{
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        auto it=q.front(); q.pop();
        if(visit[it]) return true;
        visit[it]=true;
        //work
        for(auto x:adj[it]) q.push(x->n);


        
    }
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
    }
    int src;
    cin>>src;
    
    vector<bool>visited(v+1);
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            if(isgraphcycle(adj,i,visited)) {
                cout<<"its have a graph !!";
            }
        }
    }

    

}