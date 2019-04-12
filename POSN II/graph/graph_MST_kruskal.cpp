#include "graph.h"
#include <algorithm>
#include <stdio.h>
typedef pair<int,int> ipair;

int find(int *p,int u)
{
  if (u != p[u])
    p[u] = find(p,p[u]);
  return p[u];
}
void merge(int *p,int *r,int x,int y){
  x=find(p,x);
  y=find(p,y);
  if(r[x] > r[y]) p[y] =x;
  else p[x]=y;
  if (r[x] ==r[y]) r[y]++;
}
int mst(vector<pair<int,ipair>> edges,int V)
{
  int *p = (int*)malloc((V+1)*sizeof(int));
  int *r = (int*)malloc((V+1)*sizeof(int));
  for(int i=0;i<V+1;i++) {p[i]=i;r[i]=0;}

	int mst_wt = 0;
	vector< pair<int, ipair> >::iterator it;
	for (it=edges.begin(); it!=edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;
		int set_u = find(p,u);
		int set_v = find(p,v);
		if (set_u != set_v)
		{
			cout << u << " - " << v <<"="<<it->first<< endl;
			mst_wt += it->first;
			merge(p,r,set_u, set_v);
		}
	}
  free(p);
  free(r);
	return mst_wt;
}

int main() {
  vector <pair<int,ipair>> edgelists;
  int i=0,u,v,w,V,E;
  cout<<"Number of EDGE:";cin>>E;
  cout<<"NUmber of Vertices:";cin>>V;
  while(i++<E){
    cin>>u>>v>>w;
    edgelists.push_back({w,{u,v}});
  }
  sort(edgelists.begin(),edgelists.end());
  cout<<"Edge list:"<<endl;
  int wt =mst(edgelists,V);
  cout<<"All weight ::"<<wt;
}
