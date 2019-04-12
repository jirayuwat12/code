/*
TASK: budget.cpp
LANG: c++
AUTHOR: Jirayuwat Boonchan
CENTER: PSU
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#define DIST_MAX 10001
using namespace std;

typedef vector<list<pair<int,int>>> graph;

int shortest(graph g,int u,int v){
  vector<int> dist(g.size(),DIST_MAX);
  dist[u] = 0;
  queue <int> q;
  q.push(u);
  while(!q.empty()){
    u=q.front();
    q.pop();
    list<pair<int,int>>::iterator it;
    for(it =g[u].begin();it != g[u].end();it++){
      int d=it->first;
      int w=it->second;
      if(dist[d]>dist[u]+w){
        dist[d] = dist[u] +w;
        q.push(d);
      }
    }
  }
  return dist[v];
}

pair<int,int> longest(graph g,int u,int v,int budg){
  list<pair<int,int>>::iterator it;
  vector<int> distr(g.size(),DIST_MAX);
  distr[v]=0;
  for(it=g[v].begin();it!=g[v].end();it++){
    int d= it->first;
    int w= it->second;
    if(distr[d]>distr[v]+w){
      distr[d]=distr[v]+w;
    }
  }
  int min=DIST_MAX,index;
  for(it=g[v].begin();it != g[v].end();it++){
    if(min>distr[it->first]) {min=distr[it->first];index=it->first;}
  }
  int dist = shortest(g,u,index);
  pair<int,int> ans;
  ans.first = index;
  ans.second=dist;
  return ans;
}

int find(graph g,int u,int v,int V,int budg,int left,int i){
  int dist = shortest(g,u,v);
  left = shortest(g,v,V);
  if(dist <budg){
    cout<<v<<" "<<dist<<" "<<left;
    i=1;
    return 0 ;
  }
  else if(i==1){
    return 0;
  }
  else {
  pair<int,int> ans;
  ans = longest(g,u,v,budg);
  return find(g,u,ans.first,V,budg,left,i);
  }
}

int main(){
  int V,E,v,u,budget;
  cin>>V>>E>>u>>v>>budget;
  graph g(V);
  int i,n,d,w;
  for(i=0;i<E;i++){
    cin>>n>>d>>w;
    g[n].push_back({d,w});
    g[d].push_back({n,w});
  }
  pair<int,int> ans;
  find(g,u,v,v,budget,0,0);
}
