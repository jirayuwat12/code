#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(){
	int a;
	cin>>a;
	cout<<endl;
	int p[a][2];
	int Mx=INT_MIN,mx=INT_MAX,My=INT_MIN,my=INT_MAX;
	for(int i=0;i<a;i++){
		cin>>p[i][0];
		cin>>p[i][1];
		if(mx>p[i][0]) mx=p[i][0];
		else if(Mx<p[i][0]) Mx=p[i][0];
		if(my>p[i][1]) my=p[i][1];
		else if(My<p[i][1]) My=p[i][1];
	}
	bool h;
	for(int i=My;i>=my;i--){
		for(int j=mx;j<=Mx;j++){
			h = false;
			for(int k=0;k<a;k++){
				if(p[k][0]==j && p[k][1]==i) {
					h = true;
					break;
				}
			}
			if(h==false) cout<<"  ";
			else cout<<"* ";
		}
		cout<<"\n";
	}
	float sum=0 ;
	int j,k;
	for(int i=0;i<a;i++){
		if(i+1==a) {j=i-1;k=1;}
		else if(i-1==-1) {j=a-1;k=i+1;}
		else {j=i-1;k=i+1;}
		sum += p[i][0] * p[k][1] - p[i][0] * p[j][1];
	//	cout<<sum<<" ";
	}
	sum /=2;
	cout<<endl<<sum;
}
