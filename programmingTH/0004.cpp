#include <bits/stdc++.h>
using namespace std;

int main(){
	char a[10000];
	gets(a);
	int b=strlen(a);
	int ck=0;
	for(int i=0;i<b;i++){
		if(islower(a[i])==0) ck++;
		else if(isupper(a[i])==0) ck--;
	}
	if(ck==b) cout<<"All Capital Letter";
	else if(ck==(-1*b)) cout<<"All Small Letter";
	else cout<<"Mix";
}
