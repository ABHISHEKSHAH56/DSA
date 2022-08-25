//this is type sort which help in which way work should be done efficently 
//because here some work depend on some other task 

//acyual definations is a edge uv ..u always come befor v 

// 0------>3<-----4------>6
// |       ^      |         ^
// |       |      |        |
// |       |       ----->5
// -       |
// 1------>2
//

//there is no cycle (DAG )

// 4 5 6 0 1 2 3 

//r m* w a*


#include<bits/stdc++.h>
using namespace std;

class Edges {
public:
  int s;
  int n;
  int w;
  Edges(int s, int n, int w )
  {
    this->s = s;
    this->n = n;
    this->w = w;
  }
};


//graph are given which is weighted so we need to find  a path from source to every node  within smallest cost 

void topolgicalsort(int i , vector<Edges*> adj[],vector<bool> & visited,stack<int> &st)
{
    visited[i]=true;
    for(auto it:adj[i])
    {
        if(!visited[it->n]) topolgicalsort(it->n,adj,visited,st);
    }
    st.push(i);

}


int main()
{
  int v, e;
  cin >> v >> e;
  vector<Edges*> adj[v];
  stack<int> st;
  for (int i = 0; i < e; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back(new Edges(x, y, z));
  }
  int src;
  cin >> src;

  vector<bool>visited(v);
  for(int i=0; i<=v; i++)
  {
    if(!visited[i])
    {
        topolgicalsort(i,adj,visited,st);
    }
  }
  while(!st.empty())
  {
     
  }
 



}