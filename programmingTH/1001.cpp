#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,n,m;
	bool ck=true;
	cin>>n>>m;
	char map[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<m;i++){
		cin>>x;
		ck =true;
		if(x>0)
		for(int j=-1;j<n;j++){
			if((map[j+1][i]=='O'||j == n-1) && ck) 
			for(int k=0;k<x;k++){
			ck =false;
				if(j-k>=0)map[j-k][i] = '#';
				else break;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<map[i][j];
		}
		cout<<endl;
	}
}
