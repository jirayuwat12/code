#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <stack>
#include <map>
#include <queue>
#include <limits.h>
using namespace std;

void show_graph_non_weight(vector <list <int>> adjlist){
  for(int i=0;i<adjlist.size();i++){
    cout<<"adjacency list ["<<i<<"] :";
    list<int>::iterator itr = adjlist[i].begin();

    while(itr != adjlist[i].end()){
      cout<<"->"<<*itr++<<" ";
    }cout<<endl;
  }
}
void show_graph_weight(vector <list<pair<int,int>>> adjlist){
  for(int i=0;i<adjlist.size();i++){
    cout<<"adjacency list ["<<i<<"] :";
    list<pair<int,int>>::iterator itr = adjlist[i].begin();

    while(itr != adjlist[i].end()){
      cout<<"-> "<<itr->first<<"("<<itr->second<<")"<<" ";
      itr++;
    }cout<<endl;
  }
}
