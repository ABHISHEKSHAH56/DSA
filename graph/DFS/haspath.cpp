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

bool checkhaspath(vector<Edges*> adj[],int s, int d,vector<bool>&visit)
{
    if(s==d) return true;
    visit[s]=true;
    for(auto it:adj[s])
    { 
        if(!visit[it->n])
        {
            
            bool hasneighbourpath= checkhaspath(adj,it->n,d,visit);
            if(hasneighbourpath) return true;
        }
    }
    return false;
}

//this is enough but problem is two if we dont use visit true then hum 0-1 me ghumte rhe jaayge 
//so we need visit 

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
    int s,d;
    cin>>s>>d;
    vector<bool>visited(v+1);

    // also we need for loop here also but for not that problem 
    cout<<checkhaspath(adj,s,d,visited)<<endl;
}