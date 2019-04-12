#include "graph.h"

int main(){
  /*
  std::vector<int> v;
  std::vector<list <int>> v;
  std::vector<list <pair< int,int > > v; have a weight
  */
  //vector < list<int> > adjlist_non_weight(size);
  int size =5;
  vector <list<int>> g(size);
  g[0].push_back(3);
  g[0].push_back(4);
  g[1].push_back(2);
  g[1].push_back(3);
  g[2].push_back(3);
  g[2].push_back(0);
  g[4].push_back(3);

  map <int,bool> used;
  queue <int> Q;
  int t=1;
  int bfs[size],i=0;
  list<int>::iterator itr;
  Q.push(t);
  used[t] =true;
  while(!Q.empty()){
    t = Q.front();
    bfs[i] = t;i++;
    Q.pop();
    itr = g[t].begin();
    for(itr = g[t].begin();itr != g[t].end();++itr){
      if(!used[*itr]){
        used[*itr] = true;
        Q.push(*itr);
      }
    }
  }
  for(int j=0;j<i;j++){
    cout<<bfs[j]<<" ";
  }
}
