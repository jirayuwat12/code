#include <string>
#include <iostream>
#include <map>
using namespace std;

int main(){

  string test = "Hello";
  string test2 = "World";
  string test3 = test; //"Hello"
  test3 = test +" "+test2; // "Hello World"
  int size_test3 = test3.size(); // 11
  for (int i=0;i<size_test3;i++) cout<<test3[i]<<" "; //H e l l o   W o r l d
  int locate = test3.find("lo"); // 2
  if(locate != string::npos) cout<<"\nFound at "<< locate<<endl; //Found at ...
  else cout<<"\nNot found!\n";//Not found!
  cout<<test2.compare("World")<<endl;// 0
  cout<<test2.compare("Hello")<<endl;// 1
  cout<<test2.compare("Wor")<<endl;// 2 'ld'
  cout<<test2.compare("Wo")<<endl;// 3 'rld'
}
