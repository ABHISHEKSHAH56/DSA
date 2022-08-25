#include<bits/stdc++.h>
using namespace std;
/**
 * "1. Hamiltonian Path – A simple path in a graph G   that passes through every vertex exactly once is called a Hamiltonian path.
2.  Hamiltonian cycle - if first  and last  vertex of hamilotan path share a edges then it's hamilatonian cycle "
 * 
 */
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

int n;
void hamiltonallpath(vector<Edges*> adj[],int s,vector<bool>&visit,string psf)
{
    if(psf.size()==n) {

        for(auto it :adj[psf.back()-'0']){
            if(it->n==psf[0]-'0') {
                cout<<"then found";
            }
        }
        return ;
    }
    visit[s]=true;
    for(auto it:adj[s]) if(!visit[it->n]) hamiltonallpath(adj,s,visit,psf+to_string(it->n));    
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
        //for undireted 
        adj[y].push_back(new Edges(y,x,z));
    }
    int s,d;
    cin>>s>>d;
    vector<bool>visited(v+1);

    // also we need for loop here also but for not that problem 
    hamiltonallpath(adj,s,visited,to_string(s)+"");
} 