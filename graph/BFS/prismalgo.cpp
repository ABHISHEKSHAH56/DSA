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

class Pair {
public:
  int ver;
  int weight;
  int acq;
  Pair(int vertex, int acqi, int w)
  {
    ver = vertex;
    weight = w;
    acq = acqi;
  }


};

//graph are given which is weighted so we need to find  a path from source to every node  within smallest cost 

class Compare
{
public:
  bool operator() (Pair* a, Pair* b )
  {
    if (a->weight <= b->weight) return false;
    return true;
  }
};


int main()
{
  int v, e;
  cin >> v >> e;
  vector<Edges*> adj[v];
  for (int i = 0; i < e; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back(new Edges(x, y, z));
    //for undireted 
    adj[y].push_back(new Edges(y,x,z));
  }
  int src;
  cin >> src;

  vector<bool>visited(v);
  priority_queue<Pair*, vector<Pair*>, Compare>qp;
  
  qp.push( new Pair( src,-1,0));
  while (!qp.empty())
  {
    auto it = qp.top();
    qp.pop();
    if (visited[it->acq]) continue;
    visited[it->acq] = true;
    if(it->acq!=-1)
    {
        //then we print  beacuse first node artficial hai
    }
    
    for (auto x : adj[it->acq])
    {
      
      if (!visited[x->n]) qp.push(new Pair(x->n, it->acq ,x->w ));

    }
  }



}