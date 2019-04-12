#include "graph.h"

int main(){
  int size,n,d;
  cin>>size;
  vector <list<int>> adj(size);
  cin>>n>>d;
  while(n<size && d<size){
    adj[n].push_back(d);
    adj[d].push_back(n);
    cin>>n>>d;
  }
  map <int,bool> used;
  stack <int> st;
  int t,i=0;
  cin>>t;
  int trav[size];
  list<int>::iterator itr,itre;
  st.push(t);
  used[t] = true;
  while(!st.empty()){
    t =st.top();
    st.pop();
    trav[i++] = t;
    itr = adj[t].begin();
    itre= adj[t].end();
    while (itr!=itre) {
      if(!used[*itr]){
        used[*itr] = true;
        st.push(*itr);
      }itr++;
    }
  }
  cout<<"==========="<<endl;
  for(int j=0;j<i;j++){
    cout<<trav[j]<<" ";
  }
}
