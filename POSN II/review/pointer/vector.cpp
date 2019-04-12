#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cus_com(pair<int,double> a,pair<int,double> b){
  return (a.second < b.second);
}
int main(){
//STL
  //vector : #include <vector>
    // vector <T> variable_name; T = type
    vector <int> t;
    // [] -> [1]
    t.push_back(1);
    //[1] -> [1,2]
    t.push_back(2);
    for(int i=10;i>3;i--) t.push_back(i);
    //show : t.size() is size of t
    cout<<"show value by loop for : ";
    for(int i=0;i< t.size();i++) cout<<t[i]<<" ";
    //iterator : t.begin() and t.end()
    cout<<"\n\nt.begin(pointer) : "<<*t.begin();
    cout<<endl<<"t.end(pointer) : "<<*t.end();
    cout<<endl<<"t.end - 1(pointer) : "<<*(t.end()-1);
    //insert : t.insert(index,value)
    t.insert(t.begin()+2,100);
    cout<<"\nInsert 100 to t.begin()+2(index) :";
    for(int i=0;i< t.size();i++) cout<<t[i]<<" ";
    //clear value : t.clear()
    //t.clear();
    //erase : t.erase()
    t.erase(t.begin()+1);
    //auto : for(auto i : t) cout<<i<<endl;
  	//for(auto i : t) cout<<i<<endl;
    //sort
    cout<<"\nSorted value(greater -> lower):";
    sort(t.begin(),t.end(),greater<int>());
    for (auto i :t) cout<<i<<" ";
    cout<<"\nSorted value(lower -> greater):";
    sort(t.begin(),t.end());
    for (auto i :t) cout<<i<<" ";
    // vector < pair <T1,T2> > name_value
    cout<<"\n-----vector < pair <T1,T2> > name_value----\n";
    vector < pair <int,double> > v;
    v.push_back(make_pair(10,70.0));
    v.push_back(make_pair(3,76.0));
    v.push_back(make_pair(6,43.0));
    v.push_back(make_pair(9,50.0));
    //sort vector pair
    sort(v.begin(),v.end());
    for(auto i:v) cout<<i.first<<" "<<i.second<<endl;
    //sort by custom func.
    sort(v.begin(),v.end(),cus_com);
    cout<<"\ncustom compare\n";
    for(auto i:v) cout<<i.first<<" "<<i.second<<endl;

}
