#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	int m1[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int k;
			cin>>k;
			m1[i][j]=k;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int k;
			cin>>k;
			m1[i][j]+=k;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<m1[i][j]<<" ";
		}
		cout<<endl;
	}
}
