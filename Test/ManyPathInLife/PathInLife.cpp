#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <stack>
using namespace std;

void show(int size,char te,map <char,bool> used,stack<char> st,char t,int i,vector <list<int>> adj){
  char trav[size];
  trav[size-1] = te;
  used[te] =true;
  list<int>::iterator itr,itre;
  st.push(t);
  used[t] = true;

  while(!st.empty()){
    t =st.top();
    st.pop();
    trav[i++] = t;
    itr = adj[t-97].begin();
    itre= adj[t-97].end();
    while (itr!=itre) {
      if(!used[*itr+97]){
        used[*itr+97] = true;
        st.push(*itr+97);
      }itr++;
    }
    for(int j=0;j<i;j++) cout<<trav[j]<<" ";
    cout<<trav[size-1]<<endl;
  }
}
int main(){
  int size,p;
  char n,d;
  cin>>size>>p;
  vector <list<int>> adj(size);
  for(int i=0;i<p;i++){
    cin>>n>>d;
    adj[n-97].push_back(d-97);
    adj[d-97].push_back(n-97);
  }
  map <char,bool> used;
  stack <char> st;
  int i=0;
  char t,te;
  cin>>t>>te;
  show(size,te,used,st,t,i,adj);
  // cout<<endl;
  // for(int j=0;j<i;j++) cout<<trav[j]<<" ";
}
