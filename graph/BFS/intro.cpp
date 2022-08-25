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
    queue<int>qp;
    qp.push(src);
    while(!qp.empty())
    {
        auto it=qp.front();
        qp.pop();
        if(visited[it]) continue;
        visited[it]=true;
        cout<<it<<endl;
        for(auto x:adj[it])
        {
           if(!visited[x->n]) qp.push(x->n);

        }
    }

    

}