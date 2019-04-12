#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	cin>>a;
	int x,m=INT_MAX,M=INT_MIN;
	for(int i=0;i<a;i++){
		cin>>x;
		if(x>M) M=x;
		if(x<m) m=x;
	}
	cout<<m<<endl<<M;
}
