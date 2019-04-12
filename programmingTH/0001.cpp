#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,a;
	cin>>a;
	cin>>x;
	x+=a;
	cin>>a;
	x+=a;
	if(x>=80) cout<<"A";
	else if(x>=75) cout<<"B+";
	else if(x>=70) cout<<"B";
	else if(x>=65) cout<<"C+";
	else if(x>=60) cout<<"C";
	else if(x>=55) cout<<"D+";
	else if(x>=50) cout<<"D";
	else cout<<"F";
}
