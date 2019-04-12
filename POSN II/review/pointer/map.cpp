#include <vector>
#include <map>
#include <iostream>
#include <utility>
#include <list>
using namespace std;

int main(){
  //map <T,T> name
  /*
  map <string,string> db;
  db["dog"] = "animal";
  db["house"] = "building";
  db["tree"] = "enviralment";
  string input;
  cout<<"Enter word: ";
  cin>>input;
  if(db.find(input) != db.end()) cout<<"Type is: "<<db[input];
  else cout<<"Not found!";
  */

  /*
  //found frequency of char in string
  map <char ,int> db;
  string input;
  cin>>input;
  for(int i=0;i<input.size();i++) {
    db[input[i]] ++;
  }
  for(auto i :db){
    cout<<i.first<<" "<<i.second<<endl;
  }
  */

  /*
  map <string,vector <string> > db;
  db["Dog"].push_back("Dog in Eng");db["Dog"].push_back("Dog in France");
  db["Cat"].push_back("Cat in Eng");db["Cat"].push_back("Cat in France");
  db["Horse"].push_back("Horse in Eng");db["Horse"].push_back("Horse in France");
  string input;string lang;
  cin>>input>>lang;
  int i=0;
  if(lang.compare("Eng") ==0) i=0;
  else if (lang.compare("France")==0) i=1;
  else cout<<"Sorry,don't have this lang.";
  if(i) cout<<db[input][i];
  */

  /*
  map <string,map <string,string> > db;
  db["dog"]["en"] = "dog";
  db["dog"]["fr"] = "chein";
  db["cat"]["en"] = "cat";
  db["cat"]["fr"] = "chat";
  string a,b;
  cout<<"Enter animal(dog,cat):";cin>>a;
  cout<<"Enter lang.(en,fr):";cin>>b;
  cout<<endl<<a<<" in "<<b<<" is "<<db[a][b];
  */
// 9
// 0 1
// 0 2
// 2 3
// 3 4
// 3 8
// 3 5
// 5 6
// 8 7
// 9 9
// 0
vector<list<int>> q(10);
q[0].push_back(10);
q[0].push_back(20);
cout<<q[0].size();
}
