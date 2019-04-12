#include <vector>
#include <utility>
#include <iostream>
using namespace std;

int main(){
  vector < pair<int,double> > score;
  score.push_back(make_pair(1,40.0));
  score.push_back(make_pair(2,65.0));
  score.push_back(make_pair(3,34.0));
  score.push_back(make_pair(4,56.0));
  bool ck=true;
  while(ck){
  	ck = false;
  	for(int i=0;i<score.size()-1;i++){
  		if(score[i].second > score[i+1].second){
  			int t = score[i].first;
			score[i].first = score[i+1].first;
			score[i+1].first = t;
			
			double t1 = score[i].second;
			score[i].second = score[i+1].second;
			score[i+1].second = t1;     
			ck =true;
		}
	  }
  }
  for(int i=0;i<score.size();i++){
  	cout<<score[i].first<<" "<<score[i].second<<endl;
  }
}
