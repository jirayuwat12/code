#include <bits/stdc++.h>
using namespace std;
void op(int *);
void setone(int *i);

int main(){
	int num,c,on[3],off[3];
	cin>>num>>c;
	int ion=0,ioff=0;
	cin>>on[ion];ion++;
	while(on[ion]!=-1){
		cin>>on[ion];
		ion++;
	}
	cin>>off[ioff];
	while(off[ioff]!=-1){
		cin>>off[ioff];
		ioff++;
	}
	int b[num];
	setone(&b);
	
	for(int j=0;j<c;j++){
		
	}
}
void setone(int *i){
	int j=0;
	while(*(i+j)=0);	
}
void op(int *a){
	if(*a==0) *a=1;
	else *a=0;
}
