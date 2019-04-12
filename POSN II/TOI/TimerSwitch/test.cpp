#include <iostream>
#include <fstream>
using namespace std;
int main(){
  // ifstream infile;
  // infile.open("F:\\code\\POSN II\\TOI\\TimerSwitch\\20.txt");
  // if(!infile){
  //   cout<<"Error";
  //   return 0;
  // }
  // char x;
  // long num=0;
  // while(infile >>x){
  //   cout<<x;
  //   num++;
  // }
  // cout<<endl<<num;
  // infile.close();
  char a;
  cin>>a;
  int num=1;
  while(a != 'a'){
    cin>>a;
    num++;
  }
  cout<<num;
}
