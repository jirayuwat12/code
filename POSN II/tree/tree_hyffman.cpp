#include <iostream>
#include <vector>
using namespace std;

typedef struct t {
  char a;
  int freq;
  struct t *bf,*l,*r;
}T;
void sorting(vector<pair<char,int>> *db){
  vector<pair<char,int>>::iterator *tmp ;

}
int huffman(vector<pair<char,int>> db,T *root){

  return 0;
}

int main(){
  char a[] =  {'b','a','c','d','e','f'};
  int freq[]= {13 , 45, 12, 16,  9,  5};
  vector < pair<char,int>> db;
  for(int i=0;i<6;i++) db.push_back({a[i],freq[i]});
  int size = sizeof(a)/sizeof(a[0]);
  T *root=(T *)malloc(sizeof(T));
  root->l=NULL;
  root->r=NULL;
  root->bf=NULL;
}
