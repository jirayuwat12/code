#include "graph.h"
typedef pair<int,int> ipair;

int main(){
  int i=0,V,E,u,v,w,t;
  cout<<"Vertices:";cin>>V;
  cout<<"Edges:";cin>>E;
  vector<list<ipair>> adj(V);
  while(i++<E){
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  // vector<pair<int,ipair>>::iterator its=g.begin(),ite=g.end(),run;
  // vector<pair<int,ipair>> *pg;
  cout<<"Start:";cin>>t;
  vector <int> dist(V,INT_MAX);
  dist[t]=0;
  queue<int> q;// weight , u
  q.push(t);
  while(!q.empty()){
    int tmp = q.front();
    q.pop();
    list<ipair>::iterator it;
    for(it=adj[tmp].begin();it!=adj[tmp].end();it++){
      v=it->first;
      w=it->second;
      if(dist[v]>dist[tmp]+w){
        dist[v] = dist[tmp] + w;
        q.push(v);
      }
    }
  }
  cout<<"=========="<<endl;
  for(i=0;i<V;i++){
    cout<<t<<"->"<<i<<" :"<<dist[i]<<endl;
  }
}
