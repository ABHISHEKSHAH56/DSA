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

void printallpath(vector<Edges*> adj[],int s, int d,vector<bool>&visit,string psf)
{
    if(s==d) {
        cout<<psf<<endl;
    }
    visit[s]=true;
    for(auto it:adj[s]) if(!visit[it->n]) printallpath(adj,it->n,d,visit,psf+"-"+to_string(it->n));
    // s se jane vali sari path humne likh liya hai 
    // mgr koi or path hoga jisme s se rasta jata hoga toh hume use ke liye false karna hoga
    visit[s]=false;
    
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
    printallpath(adj,s,d,visited,to_string(s)+"");
} 