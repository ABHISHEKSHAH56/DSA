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

bool isgraphcomhavebipatrate(vector<Edges*> adj[],int src ,vector<int> & visit)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    while(!q.empty())
    {
        auto it=q.front(); q.pop();
        if(visit[it.first]!=-1) {
            //means cycle is there  so we need to check odd cycle
            if(it.second!=visit[it.first]) return false;
        };
        visit[it.first]=it.second;
        //work
        for(auto x:adj[it.first]) q.push({x->n,it.second+1});


        
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
    
    vector<int>visited(v+1,-1);
    for(int i=0; i<v; i++)
    {
        if(visited[i]==-1)
        {
            if(!isgraphcomhavebipatrate(adj,i,visited)) {
                cout<<"its does not have bipatrate !!";
            }
        }
    }

    

}