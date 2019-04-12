#include "graph.h"
int minKey(int key[], bool mstSet[],int size){
  int min = INT_MAX, min_index;

  for (int v = 0; v < size; v++)
    if (mstSet[v] == false && key[v] < min)
        min = key[v], min_index = v;
  return min_index;
}
int main(){
  int size,n,d,w;
  cin>>size>>n>>d>>w;
  int g[size][size];
  while(n<size && d<size){
    g[n][d]=w;
    g[d][n]=w;
    cin>>n>>d>>w;
  }

  int parent[size],key[size];
  bool mstset[size];
  for(int i=0;i<size;i++) key[i]=INT_MAX,mstset[i]=false;
  key[0]=0;
  parent[0]=-1;

  for(int count = 0;count < size-1;count ++){
    int u = minKey(key,mstset,size);
    mstset[u]=true;
    for(int v=0;v<size;v++){
      if(g[u][v] && mstset[v] ==false && g[u][v]<key[v]){
        parent[v] = u;
        key[v] = g[u][v];
      }
    }
  }
  cout<<"======MST======"<<endl;
  for(int i=1;i<size;i++){
    cout<<parent[i]<<"<->"<<i<<" : "<<g[i][parent[i]]<<endl;
  }
}
