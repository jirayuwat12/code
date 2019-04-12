#include "graph.h"
typedef pair<int,int> ipair;

int gogo(int u,int v,vector<list<ipair>> g){
  vector<int> dist(g.size(),INT_MAX);
  dist[u]=0;
  queue <int> q;
  q.push(u);
  while(!q.empty()){
    u = q.front();
    q.pop();
    list<ipair>::iterator it;
    for(it=g[u].begin();it!=g[u].end();it++){
      int v = it->first;
      int w = it->second;
      if(dist[v] > dist[u] + w){
        dist[v]= dist[u] +w;
        q.push(v);
      }
    }
  }
  return dist[v];
}

int main(){
  int V,E,t,v,u,w=1;
  cin>>V;
  vector <list<ipair>> g(V+1);
  E = V-1;
  for(int i=0;i<E;i++){
    cin>>v>>u;
    g[v].push_back({u,w});
    g[u].push_back({v,w});
  }
  cin>>t;v=1;
  int sum = 0;
  for(int i=0;i<t;i++){
    cin>>u;
    sum+= gogo(v,u,g);
    v = u;
  }
  cout<<sum;
}
