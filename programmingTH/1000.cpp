#include <bits/stdc++.h>
using namespace std;

void swp(char *a,char *b){
	char t = *a;
	*a = *b;
	*b =t;
}
int main(){
	int k=0,l,n;
	bool ck=true;
	cin>>l>>n;
	char a[2][l];
	for(int j=0;j<l;j++){
			cin>>a[0][j];
	}
	for(int i=1;i<n &&ck;i++){
		for(int j=0;j<l;j++){
			cin>>a[1][j];
			if(a[0][j] != a[1][j]) k++;
			swp(&a[0][j],&a[1][j]);
		}
		
		if(k>2) ck =false;
		else k=0;
	}
	if(!ck)
	for(int i=0;i<l;i++){
		cout<<a[1][i];
	}
	else
	for(int i=0;i<l;i++){
		cout<<a[0][i];
	}
}
